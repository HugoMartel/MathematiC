#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

/* reprendre vid 26 */
/* gcc main.c -o aled $(sdl2-config --cflags --libs) */


void exitWithError(const char* message);

int main(int argc, char** argv)
{
    SDL_version nb;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Rect rectangle;
    rectangle.x = 12;
    rectangle.y = 100;
    rectangle.w = 300;
    rectangle.h = 100;
    SDL_Rect rect;
    rect.x = 78;
    rect.y = 400;
    rect.h = 70;
    rect.w = 140; 


    SDL_VERSION(&nb);


    printf("pitie ça marche");
    printf("\n on a la sdl %d.%d.%d", nb.major, nb.minor, nb.patch);

    SDL_Init(SDL_INIT_VIDEO);

    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) 
        exitWithError("video init");
    /* 
     * char *name, winXPosition, winYPosition, width, heigth, shown 
    window = SDL_CreateWindow("CAKNDFGSKNGDFKG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL)
       exitWithError("window creation"); 
    
     * window, driver, flags, **window, **renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL)
       exitWithError("renderer creation"); 
   */
    /* width, height, flag de creation de fenetre,  */
    if (SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
        exitWithError("renderer & window");

    /*------------------------------------------------------------------------*/
    
    /* renderer, r, g, b, alpha  */
    if (SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
        exitWithError("color change");
    /* renderer, x, y, */
    if (SDL_RenderDrawPoint(renderer, 300, 300) != 0)
        exitWithError("point");
    /*renderer,xa, ya, xb, yb */
    if (SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
        exitWithError("line");
    if (SDL_SetRenderDrawColor(renderer, 255, 66, 161, SDL_ALPHA_OPAQUE) != 0)
        exitWithError("color change");
    /* renderer, *SDL_Rect*/
    if(SDL_RenderDrawRect(renderer, &rectangle) != 0)
        exitWithError("rectangle");
    if (SDL_SetRenderDrawColor(renderer, 121, 0, 214, SDL_ALPHA_OPAQUE) != 0)
        exitWithError("color change");
    if(SDL_RenderFillRect(renderer, &rect) != 0)
        exitWithError("rectangle");
    

    SDL_RenderPresent(renderer);
    SDL_Delay(6000);
    /* clear the render  */
    SDL_RenderClear(renderer);

    /*------------------------------------------------------------------------*/
    /* Destroying the window  */
    SDL_DestroyWindow(window);
    /* Destroying the renderer */
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}

void exitWithError(const char* message) 
{
    SDL_Log("[x] SDL error in %s : %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
