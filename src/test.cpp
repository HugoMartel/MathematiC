#include <SDL2/SDL.h>   /* All SDL App's need this */
#include "../include/tmp.h"
#include <stdio.h>

int main() {
    
    printf("Initializing SDL.\n");
    
    /* Initialize defaults, Video and Audio */
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) { 
        fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }

    printf("SDL initialized.\n");

    printf("Quiting SDL.\n");
    
    /* Shutdown all subsystems */
    SDL_Quit();
    
    printf("Quiting....\n");

    printXD();

    exit(0);
}

