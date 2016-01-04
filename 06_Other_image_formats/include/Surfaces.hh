#ifndef     SURFACES_HH_
# define    SURFACES_HH_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "KeyPressSurfaces.hh"

class   Surfaces {
    public:
        Surfaces(void);
        ~Surfaces(void);
    private:
        Surfaces(const Surfaces& other);
        Surfaces& operator=(const Surfaces& other);
    public:
        bool            loadMedia(SDL_Surface* const screenSurface);
        SDL_Surface*    getSurface(const int index) const;
    private:
        SDL_Surface*    loadSurface(const char* pathToFile, SDL_Surface* const screenSurface);
        SDL_Surface*    _keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
};

#endif      /* SURFACES_HH_*/
