/**
 * @file    test.cpp
 */

/* Imgui includes */
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

/* SDL2 includes */
#if defined(_WIN32)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

/* OpenGL includes */
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#elif defined(_WIN32)
#include <SDL_opengl.h>
#else
#include <SDL2/SDL_opengl.h>
#endif
#include <GL/gl.h>

/* Custom includes */

/* STD includes */
#if defined(_WIN32)
#include <windows.h>
#endif
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string>

#define BUFF_SIZE 1000
#define MAX(a, b) (((a) < (b)) ? (b) : (a))


struct MultilineScrollState
{
    // Input.
    float scrollRegionX;
    float scrollX;
    ImGuiStorage *storage;

    // Output.
    bool newScrollPositionAvailable;
    float newScrollX;
};


/*------------------*/
/* -- PROTOTYPES -- */
/*------------------*/
static int MultilineScrollCallback(ImGuiInputTextCallbackData *data);
static bool ImGuiInputTextMultiline(const char* label, char*, size_t buf_size, float height, ImGuiInputTextFlags flags  );
static void doStyle();
static void ShowMainMenuBar();
static void menuFile();
static void save(char *);
void exitSDL(SDL_GLContext ctx, SDL_Window *win, SDL_Surface *logo);


// Main code
int main(int, char**)
{
    // Setup SDL
    // (Some versions of SDL before <2.0.10 appears to have performance/stalling issues on a minority of Windows systems,
    // depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL is recommended!)
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
    // GL 3.2 Core + GLSL 150
    const char* glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN);
    SDL_Window* window = SDL_CreateWindow("MathematiC", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, window_flags);
    if (!window) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return -1;
    }

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_Surface *logo = SDL_LoadBMP("./img/logo.bmp");
    SDL_SetWindowIcon(window, logo);
    SDL_SetWindowMinimumSize(window, 480, 500);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // -lThe fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    /* Define Window size */
    int *width = (int *) malloc(sizeof(int));
    int *height = (int *) malloc(sizeof(int));
    SDL_GetWindowSize(window, width, height);

    /* Imgui definitions */
    ImGuiWindowFlags windowFlags = (ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    char buf[1000];//! Multiline input max length
    std::string buff;



    /*-----------------*/
    /* -- Main loop -- */
    /*-----------------*/
    bool done = false;

    while (!done) {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            switch (event.type) {
            case SDL_WINDOWEVENT:
                /* Window Event */

                if (event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window)) {
                    /* Window Close Handler */
                    done = true;
                } else if (event.window.event == SDL_WINDOWEVENT_RESIZED && event.window.windowID == SDL_GetWindowID(window)) {
                    /* Window Resize Handler */
                    *width = event.window.data1;
                    *height = event.window.data2;
                    //TODO change widgets sizes using  x: event.window.data1, y: event.window.data2
                }

                break;
            case SDL_QUIT:
                /* Quit Event */
                done = true;
                break;
            default: break;
            }

        }


        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        /* Main Menu Bar */
        ShowMainMenuBar();

        /* Code widget */
        ImGui::SetNextWindowSize(ImVec2(480, *height - 20), 0);
        ImGui::SetNextWindowPos(ImVec2(0, 20), 0);

        ImGui::Begin("code", NULL, windowFlags);
        doStyle();
        //ImGui::InputTextMultiline("code", buff);
        ImGuiInputTextMultiline("", buf, 1000, *height - 150, 0);
        static int clicked = 0;
        if (ImGui::Button("Run"))
            clicked++;
        if (clicked & 1) {
            /*TODO: add calls to the run function; lex & show*/
            ImGui::SameLine();
            ImGui::Text("Calling the lex func");
        }
        ImGui::End();

        /* Graph widget */
        ImGui::SetNextWindowSize(ImVec2(*width - 480, *height - 20), 0);
        ImGui::SetNextWindowPos(ImVec2(480, 20), 0);

        ImGui::Begin("graphe", NULL, windowFlags);
        ImGui::End();


        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    exitSDL(gl_context, window, logo);

    return EXIT_SUCCESS;
}

/****************************************************************
***************************FUNCTIONS*****************************
****************************************************************/

static int MultilineScrollCallback(ImGuiInputTextCallbackData *data)
{
    MultilineScrollState *scrollState = (MultilineScrollState *)data->UserData;
    ImGuiID cursorId = ImGui::GetID("cursor");
    int oldCursorIndex = scrollState->storage->GetInt(cursorId, 0);
    if (oldCursorIndex != data->CursorPos) {
        int begin = data->CursorPos;
        while ((begin > 0) && (data->Buf[begin - 1] != '\n')) {
            --begin;
        }
        float cursorOffset = ImGui::CalcTextSize(data->Buf + begin, data->Buf + data->CursorPos).x;
        float SCROLL_INCREMENT = scrollState->scrollRegionX * 0.25f;
        if (cursorOffset < scrollState->scrollX) {
            scrollState->newScrollPositionAvailable = true;
            scrollState->newScrollX = MAX(0.0f, cursorOffset - SCROLL_INCREMENT);
        }
        else if ((cursorOffset - scrollState->scrollRegionX) >= scrollState->scrollX) {
            scrollState->newScrollPositionAvailable = true;
            scrollState->newScrollX = cursorOffset - scrollState->scrollRegionX + SCROLL_INCREMENT;
        }
    }
    scrollState->storage->SetInt(cursorId, data->CursorPos);
    return 0;
}

static bool ImGuiInputTextMultiline(const char* label, char* buf, size_t buf_size, float height, ImGuiInputTextFlags flags = 0)
{
    float scrollbarSize = ImGui::GetStyle().ScrollbarSize;
    float labelWidth = ImGui::CalcTextSize(label).x + scrollbarSize;
    float SCROLL_WIDTH = 2000.0f; // Very large scrolling width to allow for very long lines.
    MultilineScrollState scrollState = {};
    // Set up child region for horizontal scrolling of the text box.
    ImGui::BeginChild(label, ImVec2(-labelWidth, height), false, ImGuiWindowFlags_HorizontalScrollbar);
    scrollState.scrollRegionX = MAX(0.0f, ImGui::GetWindowWidth() - scrollbarSize);
    scrollState.scrollX = ImGui::GetScrollX();
    scrollState.storage = ImGui::GetStateStorage();
    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_FrameBg] = ImColor(69, 71, 91, 255);
    bool changed = ImGui::InputTextMultiline(label, buf, buf_size, ImVec2(SCROLL_WIDTH, MAX(0.0f, height - scrollbarSize)),
                                             flags | ImGuiInputTextFlags_CallbackAlways, MultilineScrollCallback, &scrollState);

    if (scrollState.newScrollPositionAvailable) {
        ImGui::SetScrollX(scrollState.newScrollX);
    }
    ImGui::EndChild();
    ImGui::SameLine();
    ImGui::Text(label);
    return changed;
}


/*Function to add bg color & style*/
static void doStyle()
{
    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImColor(40, 43, 55, 255);
}

/*funtion to show main menu*/
static void ShowMainMenuBar()
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            menuFile();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X")) {}
            if (ImGui::MenuItem("Copy", "CTRL+C")) {}
            if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

/*show main file menu*/
static void menuFile()
{
    ImGui::MenuItem("(demo menu)", NULL, false, false);
    if (ImGui::MenuItem("New")) {
        //TODO
    }
    if (ImGui::MenuItem("Open", "Ctrl+O")) {
        //TODO
    }
    if (ImGui::BeginMenu("Open Recent")) {
        ImGui::MenuItem("fish_hat.c");
        ImGui::MenuItem("fish_hat.inl");
        ImGui::MenuItem("fish_hat.h");
        if (ImGui::BeginMenu("More..")) {
            ImGui::MenuItem("Hello");
            ImGui::MenuItem("Sailor");
            ImGui::EndMenu();
        }
        ImGui::EndMenu();
    }
    if (ImGui::MenuItem("Save", "Ctrl+S")) {}
    if (ImGui::MenuItem("Save As..")) {}

    ImGui::Separator();
    if (ImGui::BeginMenu("Options")) {
        static bool enabled = true;
        ImGui::MenuItem("Enabled", "", &enabled);
        ImGui::BeginChild("child", ImVec2(0, 60), true);
        for (int i = 0; i < 10; i++)
            ImGui::Text("Scrolling Text %d", i);
        ImGui::EndChild();
        static float f = 0.5f;
        static int n = 0;
        ImGui::SliderFloat("Value", &f, 0.0f, 1.0f);
        ImGui::InputFloat("Input", &f, 0.1f);
        ImGui::Combo("Combo", &n, "Yes\0No\0Maybe\0\0");
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Colors")) {
        float sz = ImGui::GetTextLineHeight();
        for (int i = 0; i < ImGuiCol_COUNT; i++) {
            const char* name = ImGui::GetStyleColorName((ImGuiCol)i);
            ImVec2 p = ImGui::GetCursorScreenPos();
            ImGui::GetWindowDrawList()->AddRectFilled(p, ImVec2(p.x + sz, p.y + sz), ImGui::GetColorU32((ImGuiCol)i));
            ImGui::Dummy(ImVec2(sz, sz));
            ImGui::SameLine();
            ImGui::MenuItem(name);
        }
        ImGui::EndMenu();
    }

    // Here we demonstrate appending again to the "Options" menu (which we already created above)
    // Of course in this demo it is a little bit silly that this function calls BeginMenu("Options") twice.
    // In a real code-base using it would make senses to use this feature from very different code locations.
    if (ImGui::BeginMenu("Options")) {// <-- Append!
        static bool b = true;
        ImGui::Checkbox("SomeOption", &b);
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Disabled", false)) {// Disabled
        IM_ASSERT(0);
    }
    if (ImGui::MenuItem("Checked", NULL, true)) {}
    if (ImGui::MenuItem("Quit", "Alt+F4")) {}
}

/*TODO: add a way to change the filename*/
static void save(char *buff)
{
    /*getting current date/time based on OS*/
    time_t t = time(0);
    /*convert now to string*/ 
    std::tm* now = localtime(&t);
    std::stringstream fileNameStream;
    std::string fileName;
    /*filename : DD_MM_YYYY.dat*/
    fileNameStream << now->tm_mday << '_' << now->tm_mon << '_' << now->tm_year << ".dat";
    /*convert stringstream to string*/
    fileNameStream >> fileName;
    /*creating the file*/
    std::ofstream file(fileName);
    /*Writing the file*/
    for(int i = 0; i < BUFF_SIZE; ++i){
        file << buff[i];
    }
    /*closing the file*/
    file.close();    
}

/**
 * Function to call when exiting the programm
 * @param[in]   ctx     OpenGL context
 * @param[in]   win     Pointer to the main Window
 */
void exitSDL(SDL_GLContext ctx, SDL_Window *win, SDL_Surface *logo)
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_FreeSurface(logo);

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
