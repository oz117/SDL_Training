#include "Graphics.hh"

int             main(void)
{
    bool        quit;
    Graphics    g;
    SDL_Surface *imgSurface;
    SDL_Event   event;

    quit = false;
    imgSurface = NULL;
    if (g.init() == false)
        return EXIT_FAILURE;
    if (g.loadMedia("benny.bmp", &imgSurface) == false)
        return EXIT_FAILURE;
    while (quit != true)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
                quit = true;
        }
        SDL_BlitSurface(imgSurface, NULL, g.getScreenSurface(), NULL);
        SDL_UpdateWindowSurface(g.getWindow());
    }
    SDL_FreeSurface(imgSurface);
    imgSurface = NULL;
    return EXIT_SUCCESS;
}
