/**
 * @file    main.cpp
 */

/* Imgui includes */
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"

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
#include <algorithm>

#include "interface.hpp"


/** Useful max macro */
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
 * Function used to draw a Graph
 * @param[in]       width       Window width
 * @param[in]       height      Window height
 * @param[in]       interXmin   Min x value of the drawn functions, will become a table of values
 * @param[in]       interXmax   Max x value of the drawn functions
 * @param[in]       displayYmin Min y value of the function display
 * @param[in]       displayYmax Max y value of the function display
 * @param[in]       displayXmin Min x value of the function display
 * @param[in]       displayXmax Max x value of the function display
 */
static void doGraph(int *width, int *height, double interXmin, double interXmax, const double &displayYmin, const double &displayYmax, const double &displayXmin, const double &displayXmax);
/**
 * Function to display the menu bar
 * @param[in]       buff        buffer containing the code written
 * @param[in]       window      Main SDL Window
 * @param[in,out]   filename    Name of the file to possibly save to/open from
 */
static void ShowMainMenuBar(char *, SDL_Window *, std::string &, SDL_Surface *, SDL_GLContext);
/**
 * Display elements on the File option in the menu and their handlers
 * @param[in]       buff        buffer containing the code written
 * @param[in]       window      Main SDL Window
 * @param[in,out]   filename    Name of the file to possibly save to/open from
 * @param[in]       window      the SDL_window
 * @param[in]       logo        the sdl (logo)
 * @param[in]       ctx         the sdl context
 */
static void menuFile(char *, SDL_Window *, std::string &, SDL_Surface *, SDL_GLContext);

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
    int *width = new int;
    int *height = new int;
    SDL_GetWindowSize(window, width, height);

    /* Imgui definitions */
    std::string opened_file = "";
    ImGuiWindowFlags windowFlags = (ImGuiWindowFlags_NoScrollWithMouse |  ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    char *buf = (char *) malloc((BUFF_SIZE+1) * sizeof(char));//! Multiline input max length
    if(buf == NULL) exit(1);
    buf[0] = '\0';
    strcat(buf, "/**\n * @file      example.matc\n * @version 1.0.0\n */\n\n// Declarations\nvar a = 1;\nvar b = 2;\nvar c = 3;\nvar z = 5;\nvar y = 4;\n\n\n// Functions\ndef fonction1: (x) => {\n    // Function Instructions\n    if z<y {\n        if y > 0 {\n            y = sin(2);\n            z = x + y + pi;\n        } else {\n            z = cos(3);\n        }\n    } else {\n        z =  6*7;\n    }\n    return a*x^2 + b*x + c;/* simple polynomial */\n}\n\ndef g: (x) => {\n    x += 2;\n    return 2*sin(x);\n}\n\n// Draw Functions\ndraw fonction1 in [-8,8], g {\n    color: [\"red\", \"#00FF00\"],\n    style: [\"dashed\", \"solid\"],\n    label: \"Fonction 1\"\n}\n");
    /* definitions used in main loop */
    /* if true then the prog quit  */
    bool done = false;
    /* used to change the color in the output console  */
    bool isError = false;
    /* used to check the button  */
    unsigned int clicked = 0;
    /* the string shown in the console output  */
    std::string output("");
    /*-----------------*/
    /* -- Main loop -- */
    /*-----------------*/
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
        ShowMainMenuBar(buf, window, opened_file, logo, gl_context);

        /* Code widget */
        ImGui::SetNextWindowSize(ImVec2(480, *height - 20), 0);
        ImGui::SetNextWindowPos(ImVec2(0, 20), 0);

        ImGui::Begin("code", NULL, windowFlags);
        doStyle();
        /* Multiline Input */
        if (ImGuiInputTextMultiline("", buf, BUFF_SIZE, *height - 150, 0) && SDL_GetWindowTitle(window)[0] != '~') {
            /* Check if something changed in the input, if yes, then change the title */
            std::string newTitle("~ ") ;
            newTitle +=  SDL_GetWindowTitle(window);
            SDL_SetWindowTitle(window, newTitle.c_str());
        }

        /* Run Button */
        if (ImGui::Button("Run", ImVec2(50, 25))) {
            /* if pressed then we save our file  */
            if (opened_file == "") {
                /* if the file has no name then we save it  */
                opened_file = file_dialog({ {"matc", "MathematiC File"} }, true);
            }

            if (opened_file != "") {

                std::string title = "MathematiC - " + opened_file;
                title.resize(100);
                SDL_SetWindowTitle(window, title.c_str());
                /* saving the file  */
                save(buf, opened_file);
                /* calling the yy parse function (still needs to be coded under include/interface.hpp  */
                callingYYParse(opened_file);
                isError = verbose(output, isError, true);
                /* the button is clicked  */
                clicked = 1;

            }

        }

        /* Output Console  */
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        ImGui::Text("Output Console:");
        if (clicked & 1) {

            /* if we have error & output, text red and showing the lex error message  */
            if (isError && output != ""){
                ImGui::TextColored((ImVec4)ImColor::HSV(0, 0.8f, 0.8f), ("ERROR ...\n" + output).c_str());
                /* drawing the rectangle  */
                draw_list->AddRect(ImVec2(ImGui::GetItemRectMin().x - 2, ImGui::GetItemRectMin().y - 2), ImVec2(ImGui::GetWindowSize().x -15, ImGui::GetItemRectMax().y + 2), IM_COL32(255, 255, 255, 255));

            /* if not an error and we have output, so the code runned successfully  */
            } else if (!isError && output != "") {
                /* green text */
                ImGui::TextColored((ImVec4)ImColor::HSV(2 / 7.0f, 0.8f, 0.8f), ("Running ...\n" + output).c_str());
                /* rectangle arround the output */
                draw_list->AddRect(ImVec2(ImGui::GetItemRectMin().x - 2, ImGui::GetItemRectMin().y - 2), ImVec2(ImGui::GetWindowSize().x -15, ImGui::GetItemRectMax().y + 2), IM_COL32(255, 255, 255, 255));

            /* strange case: no output  */
            } else if (output == "") {
                /* red text and explanation  */
                ImGui::TextColored((ImVec4)ImColor::HSV(0, 0.8f, 0.8f), "Whoops...\nThe code did not retrieve anything...\n that\'s a strange error case...");
                /* rectangle arround it again  */
                draw_list->AddRect(ImVec2(ImGui::GetItemRectMin().x - 2, ImGui::GetItemRectMin().y - 2), ImVec2(ImGui::GetWindowSize().x -15, ImGui::GetItemRectMax().y + 2), IM_COL32(255, 255, 255, 255));
            }

        }
        /* console output */
        ImGui::End();

        /* Graph widget */
        /* setting it's position  */
        ImGui::SetNextWindowSize(ImVec2(*width - 480, *height - 20), 0);
        ImGui::SetNextWindowPos(ImVec2(480, 20), 0);

        ImGui::Begin("graphe", NULL, windowFlags);
        ImPlot::CreateContext();
        doGraph(width, height, -2.0, 12.5, -10.0, 10.0, -2.0, 12.5);
        ImPlot::DestroyContext();
        ImGui::End();

        /* detecting inputs */
        /* ctrl s, save  */
        if (io.KeyCtrl && ImGui::IsKeyDown(22)) {
            /* if no filename, when we prompt for one  */
            if (opened_file == "") {
                opened_file = file_dialog({ {"matc", "MathematiC File"} }, true);
            }
            /* saving  */
            if (opened_file != "")
                save(buf, opened_file);
        }
        /* ctrl o, open  */
        if (io.KeyCtrl && ImGui::IsKeyDown(18)) {
            opened_file = file_dialog({ {"matc", "MathematiC File"} }, false);
            if (opened_file != "")
                open(buf, opened_file);
        }
        /* ctrl q, quit */
        if (io.KeyCtrl && ImGui::IsKeyDown(20)) {
            exitSDL(gl_context, window, logo);
            exit(EXIT_SUCCESS);
        }

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
static bool ImGuiInputTextMultiline(const char* label, char* buf, size_t buf_size, float height, ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput)
{
    flags = ImGuiInputTextFlags_AllowTabInput;
    float scrollbarSize = ImGui::GetStyle().ScrollbarSize;
    float labelWidth = ImGui::CalcTextSize(label).x;
    float SCROLL_WIDTH = 750.0f; // Large scrolling width to allow for long lines.
    MultilineScrollState scrollState = {};
    // Set up child region for horizontal scrolling of the text box.
    ImGui::BeginChild(label, ImVec2(-labelWidth, height), false, ImGuiWindowFlags_HorizontalScrollbar);
    scrollState.scrollRegionX = MAX(0.0f, ImGui::GetWindowWidth() - scrollbarSize);
    scrollState.scrollX = ImGui::GetScrollX();
    scrollState.storage = ImGui::GetStateStorage();
    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_FrameBg] = ImColor(69, 71, 91, 255);
    /* if we want the horizontal scroll bar, we need to comment the SCROLL_WIDTH and replace with it ImGui::WindowSize().x, line bool changed .... 
     * also, we need to change labelWidth with ImGui::CalcTextSize(label).x;
     * and finaly we need to set scrollbarSize = ImGui::GetStyle().ScrollbarSize;
     * TODO: find better conditions to allow horizontal scroll, cause now it's a bit broken, you can only use keyboard arrows
     *       to scroll the text */
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
//TODO   add the function as parameters
static void doGraph(int *width, int *height, double interXmin, double interXmax, const double &displayYmin, const double &displayYmax, const double &displayXmin, const double &displayXmax)
{
    /* Get widget's width */
    const unsigned int sizeN = *width - 480;
    /* Points to plot coords (x,y) */
    double arrX[sizeN];
    double arrY[sizeN];

    /* step between two points plotted */
    double step1 = (1.0/sizeN) * (interXmax - interXmin);
    /* Compute coords on the interval [interXmin, interXmax] */
    for (unsigned int i = 0; i < sizeN; ++i) {
        arrY[i] = 10 * (cos(interXmin)*exp(-0.5 * interXmin));//! will change
        arrX[i] = interXmin;
        interXmin += step1;/* Corresponds to 1px *///? to check
    }

    if (ImPlot::BeginPlot("Line Plot", ImVec2(*width - 480 - 15,*height - 37))) {//! will change (label)
        /* Init Axis */
        ImPlot::SetupAxes("x", "y");
        /*Always prevents movable axis*/
        ImPlot::SetupAxesLimits(displayXmin, displayXmax, displayYmin, displayYmax, ImGuiCond_Always);

        /* PlotLine(label, x values, y values, arrays length = # of points to draw) */
        //! will change to be able to plot n functions from lexer/parser
        ImPlot::PlotLine("y=10*cos(20*x)*e^(-0.5*x)", arrX, arrY, sizeN);// First func
        ImPlot::PlotLine("y=x", arrX, arrX, sizeN);// Second func
        ImPlot::EndPlot();
    }

}

/*=======================================================================================*/
static void ShowMainMenuBar(char *buff, SDL_Window *window, std::string &filename, SDL_Surface *logo, SDL_GLContext ctx)
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            menuFile(buff, window, filename, logo, ctx);
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Shortcuts")) {
            if (ImGui::MenuItem("Undo", "CTRL+W", false, false)) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X", false, false)) {}
            if (ImGui::MenuItem("Copy", "CTRL+C", false, false)) {}
            if (ImGui::MenuItem("Paste", "CTRL+V", false, false)) {}
            ImGui::Separator();
            if(ImGui::MenuItem("Select all", "CTRL+Q", false, false)) {}
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

/*=======================================================================================*/
static void menuFile(char *buff, SDL_Window *window, std::string &filename, SDL_Surface *logo, SDL_GLContext ctx)
{
    std::string title = "MathematiC - ";

    if (ImGui::MenuItem("New")) {
        /* Empty buffer */
        buff[0] = '\0';
        filename = "";
        SDL_SetWindowTitle(window, "MathematiC - new file");
    } else if (ImGui::MenuItem("Open", "Ctrl+O")) {
        /* OPEN FILE */
        filename = file_dialog({ {"matc", "MathematiC File"} }, false);
        if (filename != "") {
            open(buff, filename);
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
        exitSDL(ctx, window, logo);
        /*This is to avoid segmentation fault*/
        exit(EXIT_SUCCESS);
    }
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
