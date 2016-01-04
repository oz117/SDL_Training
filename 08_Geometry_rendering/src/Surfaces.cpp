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
            SDL_DestroyTexture(this->_keyPressSurfaces[i]);
    }
}

bool            Surfaces::loadMedia(SDL_Renderer* const renderer)
{
    bool        success;

    success = true;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = this->loadTexture("sprite/benny.jpg", renderer);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_UP] = this->loadTexture("sprite/up.bmp", renderer);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = this->loadTexture("sprite/down.bmp", renderer);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = this->loadTexture("sprite/left.bmp", renderer);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
        success = false;
    this->_keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = this->loadTexture("sprite/right.bmp", renderer);
    if (this->_keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
        success = false;
    return success;
}

SDL_Texture*    Surfaces::loadTexture(std::string const &pathToFile, SDL_Renderer* const renderer)
{
    SDL_Texture*    newTexture;
    SDL_Surface*    imgSurface;

    imgSurface = NULL;
    newTexture = NULL;
    imgSurface = IMG_Load(pathToFile.c_str());
    if (imgSurface == NULL)
        std::cerr << "Unable to load image: " << pathToFile << "! SDL Error: " << SDL_GetError() << std::endl;
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer, imgSurface);
        if (newTexture == NULL)
            std::cerr << "Unable to optimize " << pathToFile << " SDL error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(imgSurface);
    }
    return newTexture;
}

SDL_Texture*    Surfaces::getTexture(const int index) const
{
    return this->_keyPressSurfaces[index % KEY_PRESS_SURFACE_TOTAL];
}
