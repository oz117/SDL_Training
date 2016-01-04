#include "Graphics.hh"

int main(void)
{
    Graphics g;
    SDL_Surface *imgSurface;

    imgSurface = NULL;
    if (g.init() == false)
        return EXIT_FAILURE;
    if (g.loadMedia("benny.bmp", &imgSurface) == false)
        return EXIT_FAILURE;
    SDL_BlitSurface(imgSurface, NULL, g.getScreenSurface(), NULL);
    SDL_UpdateWindowSurface(g.getWindow());
    SDL_Delay(2000);
    SDL_FreeSurface(imgSurface);
    imgSurface = NULL;
    return EXIT_SUCCESS;
}
