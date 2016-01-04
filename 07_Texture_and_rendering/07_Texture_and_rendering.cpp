#include "Graphics.hh"
#include "Surfaces.hh"

int             main(void)
{
    bool        quit;
    Graphics    g;
    Surfaces    s;
    SDL_Texture *currentTexture;
    SDL_Event   event;

    quit = false;
    currentTexture = NULL;
    if (g.init() == false)
        return EXIT_FAILURE;
    if (s.loadMedia(g.getRenderer()) == false)
        return EXIT_FAILURE;
    currentTexture = s.getTexture(KEY_PRESS_SURFACE_DEFAULT);
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
                        currentTexture = s.getTexture(KEY_PRESS_SURFACE_UP);
                        break ;
                    case SDLK_DOWN:
                        currentTexture = s.getTexture(KEY_PRESS_SURFACE_DOWN);
                        break ;
                    case SDLK_LEFT:
                        currentTexture = s.getTexture(KEY_PRESS_SURFACE_LEFT);
                        break ;
                    case SDLK_RIGHT:
                        currentTexture = s.getTexture(KEY_PRESS_SURFACE_RIGHT);
                        break ;
                    default:
                        currentTexture = s.getTexture(KEY_PRESS_SURFACE_DEFAULT);
                        break ;
                }
            }
        }
        SDL_RenderClear(g.getRenderer());
        SDL_RenderCopy(g.getRenderer(), currentTexture, NULL, NULL);
        SDL_RenderPresent(g.getRenderer());
    }
    currentTexture = NULL;
    return EXIT_SUCCESS;
}
