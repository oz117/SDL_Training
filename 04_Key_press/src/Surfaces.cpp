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

bool            Surfaces::loadMedia(void)
{
    bool        success;

    success = true;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = this->loadSurface("sprite/benny.bmp");
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_UP] = this->loadSurface("sprite/up.bmp");
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = this->loadSurface("sprite/down.bmp");
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = this->loadSurface("sprite/left.bmp");
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = this->loadSurface("sprite/right.bmp");
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
        success = false;
    return success;
}

SDL_Surface*        Surfaces::loadSurface(const char* pathToFile)
{
    SDL_Surface*    imgSurface;

    imgSurface = SDL_LoadBMP(pathToFile);
    if (imgSurface == NULL)
        std::cerr << "Unable to load image: " << pathToFile << "! SDL Error: " << SDL_GetError() << std::endl;
    return imgSurface;
}

SDL_Surface*    Surfaces::getSurface(const int index) const
{
    return this->_keyPressSurfaces[index % KEY_PRESS_SURFACE_TOTAL];
}
