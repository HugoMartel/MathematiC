/**
 * @file test_input.cpp 
 */

#include <sdlgui/screen.h>
#include <sdlgui/window.h>
#include <sdlgui/layout.h>
#include <sdlgui/label.h>
// #include <sdlgui/checkbox.h>
#include <sdlgui/button.h>
// #include <sdlgui/toolbutton.h>
// #include <sdlgui/popupbutton.h>
// #include <sdlgui/combobox.h>
#include <sdlgui/dropdownbox.h>
// #include <sdlgui/progressbar.h>
// #include <sdlgui/entypo.h>
// #include <sdlgui/messagedialog.h>
// #include <sdlgui/textbox.h>          //! Replaced with include/multibox.h which modifies the header to enable multiline editing
// #include <sdlgui/slider.h>
// #include <sdlgui/imagepanel.h>
// #include <sdlgui/imageview.h>
// #include <sdlgui/vscrollpanel.h>
// #include <sdlgui/colorwheel.h>
//#include <sdlgui/graph.h>             //! Replaced with include/curve.h which add functionalities to the functions drawn 
// #include <sdlgui/tabwidget.h>
// #include <sdlgui/switchbox.h>
// #include <sdlgui/formhelper.h>
#include <memory>

#if defined(_WIN32)
#include <windows.h>
#endif
#include <iostream>

/* SDL2 */
#if defined(_WIN32)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
/* SDL2 Image*/
#if defined(_WIN32)
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif
/* OpenGL */
#if defined(_WIN32)
#include <SDL_opengl.h>
#else
#include <SDL2/SDL_opengl.h>
#endif
#include <GL/gl.h>

/* Custom nanogui headers */
#include "../include/multibox.h"
#include "../include/curve.h"

using std::cerr;
using std::cout;
using std::endl;

#undef main

#define WIDTH 1280
#define HEIGHT 720

using namespace sdlgui;


/**
 * @brief Class used to setup and store every widget on the main program window
 * @details inherits from sdlgui::Screen
 * @see sdlgui::Screen
 */
class MainWindow : public sdlgui::Screen
{
private:
    sdlgui::Window *graphWindow;
    sdlgui::Window *codeWindow;

public:
    /**
     * @brief       Contructs the main window displayed by the program
     * @pre         rwidth and rheight >= 0
     * @param[in]   pwindow     Screen to create the windows into
     * @param[in]   rwidth      Screen width
     * @param[in]   rheight     Screen height
     */
    MainWindow(SDL_Window *pwindow, const int &rwidth, const int &rheight)
        : sdlgui::Screen(pwindow, sdlgui::Vector2i(rwidth, rheight), "MathematiC")
    {
        
        /* Curve window (right) */
        {
            /* Init window */
            graphWindow = &wdg<sdlgui::Window>("Graph");
            graphWindow->setPosition(sdlgui::Vector2i({475, 0}));
            graphWindow->setFixedSize(sdlgui::Vector2i(805, 720));
            graphWindow->setLayout(new sdlgui::GroupLayout());

            /* Init curve widget */
            sdlgui::Curve *curve = graphWindow->add<sdlgui::Curve>("y");
            curve->setFixedSize(sdlgui::Vector2i(780, 670));
            curve->setLayout(new sdlgui::GroupLayout(15,6, 14, 20));

            /* Setup the axis and draw the curve */
            curve->setHeader("Function Name");
            curve->setFooter("x");
            std::vector<float> &func = curve->values();
            func.resize(100);
            for (int i = 0; i < 100; ++i) {
                func[i] = 0.5f * (0.5f * std::sin(i / 10.f) +
                          0.5f * std::cos(i / 23.f) + 1);
            }

        }

        /* Code window (left) */
        {
            /* Init window */
            codeWindow = &wdg<sdlgui::Window>("Configuration");
            codeWindow->setPosition(sdlgui::Vector2i({0, 0}));
            codeWindow->setSize(sdlgui::Vector2i(480, 720));

            sdlgui::GridLayout *layout = new GridLayout(
                sdlgui::Orientation::Vertical, 
                3, 
                sdlgui::Alignment::Middle, 
                0, 
                10
            );
            layout->setSpacing(0, 10);
            codeWindow->setLayout(layout);

            /* Empty holder Widget */
            sdlgui::Widget *holder = codeWindow->add<sdlgui::Widget>();
            holder->withLayout<sdlgui::BoxLayout>(sdlgui::Orientation::Horizontal, sdlgui::Alignment::Middle, 0, 6);

            /* Save/Open file */
            sdlgui::Button *openButton = holder->add<sdlgui::Button>("Open");
            openButton->withCallback([&] {
                std::cout << "File dialog result: " << sdlgui::file_dialog(
                                { {"matc", "MathematiC File"} }, false) << std::endl;
            });

            sdlgui::Button *saveButton = holder->add<sdlgui::Button>("Save");
            saveButton->withCallback([&] {
                std::cout << "File dialog result: " << sdlgui::file_dialog(
                                { {"matc", "MathematiC File"} }, true) << std::endl;
            });


            /* Curve type dropdown */
            sdlgui::Label *dropdownLabel = holder->add<sdlgui::Label>("Graph Type", "sans-bold");
            sdlgui::DropdownBox &dropdownBox = holder->wdg<sdlgui::DropdownBox>();
            dropdownBox.setItems(std::vector<std::string>{"Simple", "Parametric", "Fractal"});
            dropdownBox.setSelectedIndex(0);
            // TODO: detect value change

            /* Code input */
            codeWindow->add<Label>("Code :", "sans-bold");
            sdlgui::MultiBox &multiBox = codeWindow->wdg<sdlgui::MultiBox>();
            multiBox.setEditable(true);
            multiBox.setSize(sdlgui::Vector2i(460, 600));
            multiBox.setValue("// test code\nconsole(\"Hello World!\");");//!\ \n not working
            multiBox.setFontSize(16);
            multiBox.setAlignment(sdlgui::MultiBox::Alignment::Left);
            /* TODO: check if format is good, using basic regex which is allowing almost everything
            * old regex: [0-9a-zA-Z\?\+\-\*\/\>\<\_\=\"\'\n\&\#\\(\)~|\[\]\{\} ]*
            * shit has been updated by tt
            * Needs to be edited to some sort of format in order to not let pass everything
            */
            //=> is crashing the prog but when the regex is hard coded into the checkFormat func it's working ???
            //multiBox.setFormat("[0-9a-zA-Z\?\+\-\*\/\_\=\"\'\n\&\#\\(\)~|\[\]\{\} ]*");//!\ not working <!> technicaly not fixed

            /* Run code button */
            //TODO
        }
        performLayout(mSDL_Renderer);
    }

    /**
     *
     */
    ~MainWindow()
    {
    }

    /**
     *
     */
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

    /**
     *
     */
    virtual void draw(SDL_Renderer *renderer)
    {
        //! Maybe use it again when pressing the run button
        /*
        if (sdlgui::Widget * pbar = gfind<ProgressBar>("progressbar"))
        {
            pbar->setValue(pbar->value() + 0.001f);
            if (pbar->value() >= 1.f)
                pbar->setValue(0.f);
        }
        */

        sdlgui::Screen::draw(renderer);
    }

    /**
     *
     */
    virtual void drawContents()
    {
    }

    /**
     *
     */
    void setWindowSize(const int& width, const int& height)
    {
        /* Change code's height since it will remain at 480 */
        codeWindow->setSize(sdlgui::Vector2i(480, height));

        /* Change graph's size */
        graphWindow->setSize(sdlgui::Vector2i(width-480, height));

    }
};

/**
 * 
 */
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

/**
 * 
 */
void initGL() {

}


/*================*/
/* -    MAIN    - */
/*================*/
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

    int winWidth = WIDTH;
    int winHeight = HEIGHT;

    bool isFullscreen = false;

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "MathematiC",                                                   //    const char* title
        SDL_WINDOWPOS_UNDEFINED,                                        //    int x: initial x position
        SDL_WINDOWPOS_UNDEFINED,                                        //    int y: initial y position
        winWidth,                                                       //    int w: width, in pixels
        winHeight,                                                      //    int h: height, in pixels
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE  //    Uint32 flags: window options, see docs
    );
    SDL_SetWindowIcon(window, IMG_Load("./img/logo.svg"));
    SDL_SetWindowMinimumSize(window, 480, 500);

    // Check that the window was successfully made
    if (window == NULL) {
        // In the event that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_GLContext context = SDL_GL_CreateContext(window);

    for (int it = 0; it < SDL_GetNumRenderDrivers(); it++) {
        SDL_GetRenderDriverInfo(it, &info);
        strcat(rendername, info.name);
        strcat(rendername, " ");
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    MainWindow *screen = new MainWindow(window, winWidth, winHeight);

    Fps fps;

   

    bool quit = false;
    try {

        /*==================*/
        /* -    EVENTS    - */
        /*==================*/

        SDL_Event e;
        while (!quit) {
            //Handle events on queue
            while (SDL_PollEvent(&e) != 0) {
                /*User requests quit*/
                if (e.type == SDL_QUIT) {
                    quit = true;
                } else if (e.type == SDL_WINDOWEVENT) {
                    /* Window resize handler */
                    if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
                        /* Change Widgets size */
                        screen->setWindowSize(e.window.data1, e.window.data2);
                        screen->draw(renderer);
                    }
                
                } else if (e.type == SDL_KEYUP) {
                    switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    case SDLK_f:
                        isFullscreen = !isFullscreen;
                        if (isFullscreen) {
                            SDL_SetWindowFullscreen(window, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP);
                        } else {
                            SDL_SetWindowFullscreen(window, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
                        }
                        break;
                    default:
                        break;
                    }
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


    } catch (const std::runtime_error &e) {
        std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
#if defined(_WIN32)
        MessageBoxA(nullptr, error_msg.c_str(), NULL, MB_ICONERROR | MB_OK);
#else
        std::cerr << error_msg << endl;
#endif
        return -1;
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);

    return EXIT_SUCCESS;
}
