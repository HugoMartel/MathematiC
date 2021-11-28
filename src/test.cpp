// Dear ImGui: standalone example application for SDL2 + OpenGL
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include <cstdint>
#include <stdio.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif
#define BUFF_SIZE 500
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#include <string>

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


static int MultilineScrollCallback(ImGuiInputTextCallbackData *data);
static bool ImGuiInputTextMultiline(const char* label, char*, size_t buf_size, float height, ImGuiInputTextFlags flags  );
static void doStyle();
static void ShowMainMenuBar(char *, SDL_Window *);
static void menuFile(char *, SDL_Window *);
static void save(char *, std::string);

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
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("MathematiC", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_SetWindowTitle(window, "MathematiC - new file");
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

    // Our state
    bool show_code = true;
    bool show_graph = true;
    /*getting window size*/
    int *width = (int *) malloc(sizeof(int));
    int *height = (int *) malloc(sizeof(int));
    SDL_GetWindowSize(window, width, height);
    /*Some definitions*/
    ImVec2 codeSize(*(width)/3, *(height) - 20);
    ImVec2 codePos(0, 20);
    ImVec2 graphSize(2*(*width)/3, *(height) - 20);
    ImVec2 graphPos(*(width)/3, 20);
    ImGuiWindowFlags windowFlags = (ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    char *buf = (char *) malloc(BUFF_SIZE * sizeof(char) + 1);
    buf[0] = '\0';
    //char buf[BUFF_SIZE] = "//enter your code here\n";
    std::string buff;
    // Main loop
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
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        ShowMainMenuBar(buf, window);
        ImVec2 codeSize(*(width)/3, *(height));
        /*setting windowsize and position*/
        ImGui::SetNextWindowSize(codeSize, 0);
        ImGui::SetNextWindowPos(codePos, 0);
        if (show_code) { //code part
            ImGui::Begin("code", NULL, windowFlags);
            doStyle();
            //ImGui::InputTextMultiline("code", buff);
            ImGuiInputTextMultiline("", buf, BUFF_SIZE, *height - 150, 0);
            static int clicked = 0;
            if (ImGui::Button("Run"))
                clicked++;
            if (clicked & 1) {
                /*TODO: add calls to the run function; lex & show*/
                ImGui::SameLine();
                ImGui::Text("Calling the lex func");
            } 
            ImGui::End();
        }
        ImGui::SetNextWindowSize(graphSize, 0);
        ImGui::SetNextWindowPos(graphPos, 0);
        if (show_graph) { //graph part 
            ImGui::Begin("graphe", NULL, windowFlags);
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
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
static void ShowMainMenuBar(char *buff, SDL_Window *window)
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            menuFile(buff, window);
            ImGui::EndMenu();                    
        }
        /*if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X")) {}
            if (ImGui::MenuItem("Copy", "CTRL+C")) {}
            if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                ImGui::EndMenu();
        }*/
        ImGui::EndMainMenuBar();
    }
}

/*show main file menu*/
static void menuFile(char *buff, SDL_Window *window)
{
    std::string filename("");
    ImGui::MenuItem("(MathematiC)", NULL, false, false);
    if (ImGui::MenuItem("New")) {
        free(buff);
        buff = (char *) malloc(BUFF_SIZE * sizeof(char));
        buff[0] = '\0';
    }
    if (ImGui::MenuItem("Open", "Ctrl+O")) {
        //TODO
    }
    if (ImGui::MenuItem("Save", "Ctrl+S")) {
        //TODO
        if(filename == ""){
            goto SAVEAS;         
        }
        else{
            save(buff, filename); 
        }
        SDL_SetWindowTitle(window, ("MathematiC - " + filename + ".dat").c_str());
    }
    if (ImGui::MenuItem("Save As..")) {
        SAVEAS: printf("guihfduigh");
    }

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
    // Of course in this demo it is a little bit silly that this function calls BeginMenu("Options") twice.
    // In a real code-base using it would make senses to use this feature from very different code locations.
    /*if (ImGui::BeginMenu("Options")) {// <-- Append!
        static bool b = true;
        ImGui::Checkbox("SomeOption", &b);
        ImGui::EndMenu();
    }*/
    if (ImGui::MenuItem("Checked", NULL, true)) {}
    if (ImGui::MenuItem("Quit", "")) {
        SDL_Quit();
    }
}

static void save(char *buff, std::string filename)
{
    filename += ".dat";
    /*creating the file*/
    std::ofstream file(filename);
    /*Writing the file*/
    int i = 0;
    while (i < BUFF_SIZE && buff[i] != '\0') {
        file << buff[i];
        ++i;
    }
    /*closing the file*/
    file.close();    
}

