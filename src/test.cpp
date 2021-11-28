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
#include "zenity.hpp"

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

#define BUFF_SIZE 2000
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
/**
 * Handler for the scroll event on the multiline input
 * @param[in]   data    Shared state of the InputText()
 * @return      0 by default
 */
static int MultilineScrollCallback(ImGuiInputTextCallbackData *data);
/**
 * Init the multiline text input
 * @param[in]   label   Label of the widget
 * @param[in]   buf     buffer with the content of the input
 * @param[in]   buf_size    max size of the text
 * @param[in]   height  height of the Input (to detect possible scroll)
 * @param[in]   flags   Imgui Text Widget flags
 * @return      true: input value changed, false otherwise
 */
static bool ImGuiInputTextMultiline(const char* label, char* buf, size_t buf_size, float height, ImGuiInputTextFlags flags);
/**
 * Function to add background color & style to the window and Imgui elements
 */
static void doStyle();
/**
 * Function to display the menu bar
 * @param[in]       buff        buffer containing the code written
 * @param[in]       window      Main SDL Window
 * @param[in,out]   filename    Name of the file to possibly save to/open from
 */
static void ShowMainMenuBar(char *, SDL_Window *, std::string &);
/**
 * Display elements on the File option in the menu and their handlers
 * @param[in]       buff        buffer containing the code written
 * @param[in]       window      Main SDL Window
 * @param[in,out]   filename    Name of the file to possibly save to/open from
 */
static void menuFile(char *, SDL_Window *, std::string &);
//TODO static void editFile();
/**
 * Save a given text buffer to a file
 * @param[in]   buff        text to save
 * @param[in]   filename    path of the file to save to
 */
static void save(char *, std::string &);
/**
 * Open a given file to a text buffer
 * @param[in]   buff        buffer to write the text to
 * @param[in]   filename    path of the file to open
 */
static void open(char *, std::string &);
/**
 * Function to call when exiting the programm
 * @param[in]   ctx     OpenGL context to free
 * @param[in]   win     Pointer to the main Window to free
 * @param[in]   logo    Logo surface to free
 */
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
    SDL_Window* window = SDL_CreateWindow("MathematiC - new file", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, window_flags);
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
    std::string opened_file = "";
    ImGuiWindowFlags windowFlags = (ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    char *buf = (char *) malloc((BUFF_SIZE+1) * sizeof(char));//! Multiline input max length
    if(buf == NULL) exit(1);
    buf[0] = '\0';
    //char buf[BUFF_SIZE] = "//enter your code here\n";
    strcat(buf, "/**\n * @file      example.matc\n * @version 1.0.0\n */\n\n// Declarations\nvar a = 1;\nvar b = 2;\nvar c = 3;\nvar z = 5;\nvar y = 4;\n\n\n// Functions\ndef fonction1: (x) => {\n    // Function Instructions\n    if z<y {\n        if y > 0 {\n            y = sin(2);\n            z = x + y + pi;\n        } else {\n            z = cos(3);\n        }\n    } else {\n        z =  6*7;\n    }\n    return a*x^2 + b*x + c;/* simple polynomial */\n}\n\ndef g: (x) => {\n    x += 2;\n    return 2*sin(x);\n}\n\n// Draw Functions\ndraw fonction1 in [-8,8], g {\n    color: [\"red\", \"#00FF00\"],\n    style: [\"dashed\", \"solid\"],\n    label: \"Fonction 1\"\n}\n");



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
        ShowMainMenuBar(buf, window, opened_file);

        /* Code widget */
        ImGui::SetNextWindowSize(ImVec2(480, *height - 20), 0);
        ImGui::SetNextWindowPos(ImVec2(0, 20), 0);

        ImGui::Begin("code", NULL, windowFlags);
        doStyle();
        if (ImGuiInputTextMultiline("", buf, BUFF_SIZE, *height - 75, 0) && SDL_GetWindowTitle(window)[0] != '~') {
            /* Check if something changed in the input, if yes, then change the title */
            std::string newTitle("~ ") ;
            newTitle +=  SDL_GetWindowTitle(window);
            SDL_SetWindowTitle(window, newTitle.c_str());
        }
        static int clicked = 0;
        if (ImGui::Button("Run", ImVec2(50, 25)))
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

        ImGui::Begin("graph", NULL, windowFlags);
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

/*---------------------*/
/* --   FUNCTIONS   -- */
/*---------------------*/
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

/*=======================================================================================*/
static bool ImGuiInputTextMultiline(const char* label, char* buf, size_t buf_size, float height, ImGuiInputTextFlags flags = 0)
{
    float scrollbarSize = ImGui::GetStyle().ScrollbarSize;
    float labelWidth = ImGui::CalcTextSize(label).x + scrollbarSize;
    float SCROLL_WIDTH = 750.0f; // Large scrolling width to allow for long lines.
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

/*=======================================================================================*/
static void doStyle()
{
    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImColor(40, 43, 55, 255);
}

/*=======================================================================================*/
static void ShowMainMenuBar(char *buff, SDL_Window *window, std::string &filename)
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            menuFile(buff, window, filename);
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

/*=======================================================================================*/
static void menuFile(char *buff, SDL_Window *window, std::string &filename)
{
    std::string title = "MathematiC - ";

    if (ImGui::MenuItem("New")) {
        /* Empty buffer */
        buff[0] = '\0';
        SDL_SetWindowTitle(window, "MathematiC - new file");
    } else if (ImGui::MenuItem("Open", "Ctrl+O")) {
        /* OPEN FILE */
        filename = file_dialog({ {"matc", "MathematiC File"} }, false);
        printf("To open: %s\n", filename.c_str());
        if (filename != "") {
            //TODO
            title += filename;
            title.resize(100);
            SDL_SetWindowTitle(window, title.c_str());
        }
    } else if (ImGui::MenuItem("Save", "Ctrl+S")) {
        /* SAVE FILE */
        if(filename == "") {
            filename = file_dialog({ {"matc", "MathematiC File"} }, true);
            if (filename != "") {
                save(buff, filename);
                title += filename;
                title.resize(100);
                SDL_SetWindowTitle(window, title.c_str());
            }
        }
        else{
            save(buff, filename);
        }
    } else if (ImGui::MenuItem("Save As..")) {
        /* SAVE AS FILE */
        filename = file_dialog({ {"matc", "MathematiC File"} }, true);
        if (filename != "") {
            save(buff, filename);
            title += filename;
            title.resize(100);
            SDL_SetWindowTitle(window, title.c_str());
        }
    }

    ImGui::Separator();

    if (ImGui::MenuItem("Quit", "")) {
        SDL_Quit();
    }
}

/*=======================================================================================*/
static void open(char *buff, std::string &filename)
{
    //TODO
}

/*=======================================================================================*/
static void save(char *buff, std::string &filename)
{
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

/*=======================================================================================*/
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
