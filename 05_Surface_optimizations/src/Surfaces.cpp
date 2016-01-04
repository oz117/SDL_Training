#include "Surfaces.hh"

Surfaces::Surfaces(void)
{
    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
    {
        this->_keyPressSurfaces[i] = NULL;
    }
}

Surfaces::~Surfaces(void)
{
    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
    {
        if (this->_keyPressSurfaces[i] != NULL)
            SDL_FreeSurface(this->_keyPressSurfaces[i]);
    }
}

bool            Surfaces::loadMedia(SDL_Surface* const screenSurface)
{
    bool        success;

    success = true;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = this->loadSurface("sprite/fisheye_placebo.bmp", screenSurface);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_UP] = this->loadSurface("sprite/up.bmp", screenSurface);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = this->loadSurface("sprite/down.bmp", screenSurface);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = this->loadSurface("sprite/left.bmp", screenSurface);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = this->loadSurface("sprite/right.bmp", screenSurface);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
        success = false;
    return success;
}

SDL_Surface*        Surfaces::loadSurface(const char* pathToFile, SDL_Surface* const screenSurface)
{
    SDL_Surface*    imgSurface;
    SDL_Surface*    optimizedSurface;

    imgSurface = NULL;
    optimizedSurface = NULL;
    imgSurface = SDL_LoadBMP(pathToFile);
    if (imgSurface == NULL)
        std::cerr << "Unable to load image: " << pathToFile << "! SDL Error: " << SDL_GetError() << std::endl;
    else
    {
        optimizedSurface = SDL_ConvertSurface(imgSurface, screenSurface->format, 0);
        if (optimizedSurface == NULL)
            std::cerr << "Unable to optimize " << pathToFile << " SDL error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(imgSurface);
    }
    return optimizedSurface;
}

SDL_Surface*    Surfaces::getSurface(const int index) const
{
    return this->_keyPressSurfaces[index % KEY_PRESS_SURFACE_TOTAL];
}
