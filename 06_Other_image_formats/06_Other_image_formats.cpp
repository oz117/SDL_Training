#include "Graphics.hh"
#include "Surfaces.hh"

int             main(void)
{
    bool        quit;
    Graphics    g;
    Surfaces    s;
    SDL_Surface *currentSurface;
    SDL_Event   event;
    SDL_Rect    stretchRect;

    quit = false;
    currentSurface = NULL;
    if (g.init() == false)
        return EXIT_FAILURE;
    if (s.loadMedia(g.getScreenSurface()) == false)
        return EXIT_FAILURE;
    currentSurface = s.getSurface(KEY_PRESS_SURFACE_DEFAULT);
    while (quit != true)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
                quit = true;
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        currentSurface = s.getSurface(KEY_PRESS_SURFACE_UP);
                        break ;
                    case SDLK_DOWN:
                        currentSurface = s.getSurface(KEY_PRESS_SURFACE_DOWN);
                        break ;
                    case SDLK_LEFT:
                        currentSurface = s.getSurface(KEY_PRESS_SURFACE_LEFT);
                        break ;
                    case SDLK_RIGHT:
                        currentSurface = s.getSurface(KEY_PRESS_SURFACE_RIGHT);
                        break ;
                    default:
                        currentSurface = s.getSurface(KEY_PRESS_SURFACE_DEFAULT);
                        break ;
                }
            }
        }
        stretchRect.x = 0;
		stretchRect.y = 0;
		stretchRect.w = SCREEN_WIDTH;
		stretchRect.h = SCREEN_HEIGHT;
        SDL_BlitScaled(currentSurface, NULL, g.getScreenSurface(), &stretchRect);
        SDL_UpdateWindowSurface(g.getWindow());
    }
    currentSurface = NULL;
    return EXIT_SUCCESS;
}
