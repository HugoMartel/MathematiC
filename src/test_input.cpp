/**
 * @file test_input.cpp 
 */

#include <sdlgui/screen.h>
#include <sdlgui/window.h>
#include <sdlgui/layout.h>
#include <sdlgui/label.h>
#include <sdlgui/checkbox.h>
#include <sdlgui/button.h>
#include <sdlgui/toolbutton.h>
#include <sdlgui/popupbutton.h>
#include <sdlgui/combobox.h>
#include <sdlgui/dropdownbox.h>
#include <sdlgui/progressbar.h>
#include <sdlgui/entypo.h>
#include <sdlgui/messagedialog.h>
#include <sdlgui/textbox.h>
#include <sdlgui/slider.h>
#include <sdlgui/imagepanel.h>
#include <sdlgui/imageview.h>
#include <sdlgui/vscrollpanel.h>
#include <sdlgui/colorwheel.h>
#include <sdlgui/graph.h>
#include <sdlgui/tabwidget.h>
#include <sdlgui/switchbox.h>
#include <sdlgui/formhelper.h>
#include <memory>

#if defined(_WIN32)
#include <windows.h>
#endif
#include <iostream>

#if defined(_WIN32)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#if defined(_WIN32)
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

using std::cerr;
using std::cout;
using std::endl;

#undef main

using namespace sdlgui;

class TestWindow : public Screen
{
public:
    TestWindow(SDL_Window *pwindow, int rwidth, int rheight)
        : Screen(pwindow, Vector2i(rwidth, rheight), "MathematiC")
    {

        {
            /* OpenGL window */
            //TODO
        }

        {
            /* Init code window */
            sdlgui::Window &window = wdg<Window>("Configuration");
            window.withPosition({0, 0});
            sdlgui::GridLayout *layout = new GridLayout(
                Orientation::Horizontal, 
                1, 
                Alignment::Middle, 
                15, 
                5
            );
            layout->setColAlignment({Alignment::Maximum, Alignment::Fill});
            layout->setSpacing(0, 10);
            window.setLayout(layout);

            /* Curve type dropdown */
            window.add<Label>("Graph Type", "sans-bold");
            sdlgui::DropdownBox &dropdownBox = window.wdg<DropdownBox>();
            dropdownBox.setItems(std::vector<std::string>{"Simple", "Parametric", "Fractal"});
            dropdownBox.setSelectedIndex(0);
            // TODO: detect value change

            /* Code input */
            window.add<Label>("Code :", "sans-bold");
            sdlgui::TextBox &textBox = window.wdg<TextBox>();
            textBox.setEditable(true);
            textBox.setFixedSize(Vector2i(400, 600));
            textBox.setValue("// test code\nconsole(\"Hello World!\");");//! \n not working
            textBox.setFontSize(16);
            //textBox.setFormat("[0-9a-zA-Z\?\+\-\*\/\>\<\_\=\"\'\n\&\#\~|\[\]\{\}\ ]*");//! not working

            /* Run code button */
            //TODO
        }
        performLayout(mSDL_Renderer);
    }

    ~TestWindow()
    {
    }

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers)
    {
        if (Screen::keyboardEvent(key, scancode, action, modifiers))
            return true;

        //if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        // {
        //    setVisible(false);
        //    return true;
        //}
        return false;
    }

    virtual void draw(SDL_Renderer *renderer)
    {
        /*
        if (auto pbar = gfind<ProgressBar>("progressbar"))
        {
            pbar->setValue(pbar->value() + 0.001f);
            if (pbar->value() >= 1.f)
                pbar->setValue(0.f);
        }
        */

        Screen::draw(renderer);
    }

    virtual void drawContents()
    {
    }

private:
    std::vector<SDL_Texture *> mImagesData;
    int mCurrentImage;
};

class Fps
{
public:
    explicit Fps(int tickInterval = 30)
        : m_tickInterval(tickInterval), m_nextTime(SDL_GetTicks() + tickInterval)
    {
    }

    void next()
    {
        SDL_Delay(getTicksToNextFrame());

        m_nextTime += m_tickInterval;
    }

private:
    const int m_tickInterval;
    Uint32 m_nextTime;

    Uint32 getTicksToNextFrame() const
    {
        Uint32 now = SDL_GetTicks();

        return (m_nextTime <= now) ? 0 : m_nextTime - now;
    }
};

int main(int /* argc */, char ** /* argv */)
{
    char rendername[256] = {0};
    SDL_RendererInfo info;

    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

    SDL_Window *window; // Declare a pointer to an SDL_Window

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    int winWidth = 1024;
    int winHeight = 768;

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                                               //    const char* title
        SDL_WINDOWPOS_UNDEFINED,                                        //    int x: initial x position
        SDL_WINDOWPOS_UNDEFINED,                                        //    int y: initial y position
        winWidth,                                                       //    int w: width, in pixels
        winHeight,                                                      //    int h: height, in pixels
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI //    Uint32 flags: window options, see docs
    );

    // Check that the window was successfully made
    if (window == NULL)
    {
        // In the event that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    auto context = SDL_GL_CreateContext(window);

    for (int it = 0; it < SDL_GetNumRenderDrivers(); it++)
    {
        SDL_GetRenderDriverInfo(it, &info);
        strcat(rendername, info.name);
        strcat(rendername, " ");
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    TestWindow *screen = new TestWindow(window, winWidth, winHeight);

    Fps fps;

    bool quit = false;
    try
    {
        SDL_Event e;
        while (!quit)
        {
            //Handle events on queue
            while (SDL_PollEvent(&e) != 0)
            {
                //User requests quit
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                screen->onEvent(e);
            }

            SDL_SetRenderDrawColor(renderer, 0xd3, 0xd3, 0xd3, 0xff);
            SDL_RenderClear(renderer);

            screen->drawAll();

            // Render the rect to the screen
            SDL_RenderPresent(renderer);

            fps.next();
        }
    }
    catch (const std::runtime_error &e)
    {
        std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
#if defined(_WIN32)
        MessageBoxA(nullptr, error_msg.c_str(), NULL, MB_ICONERROR | MB_OK);
#else
        std::cerr << error_msg << endl;
#endif
        return -1;
    }
    return 0;
}