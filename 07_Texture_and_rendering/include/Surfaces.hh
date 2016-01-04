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
        bool            loadMedia(SDL_Renderer* const renderer);
        SDL_Texture*    getTexture(int const index) const;
    private:
        SDL_Texture*    loadTexture(std::string const &pathToFile, SDL_Renderer* const renderer);
        SDL_Texture*    _keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
};

#endif      /* SURFACES_HH_*/
