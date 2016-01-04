#include "Graphics.hh"

/*
 * initializes the two pointer attributes to NULL (window and it's surface)
 */
Graphics::Graphics(void)
{
    this->_window = NULL;
    this->_screenSurface = NULL;
}

/*
 * Destroy the window properly and resets the pointer to NULL
 */
Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
    this->_window = NULL;
    SDL_Quit();
}

SDL_Surface*    Graphics::getScreenSurface(void) const
{
    return this->_screenSurface;
}

SDL_Window*     Graphics::getWindow(void) const
{
    return this->_window;
}

/*
 * Initializes the window and set it's corresponding Surface
 */
bool        Graphics::init()
{
    bool    success;
    int     imgFlags;

    success = true;
    imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        success = false;
        std::cerr << "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << std::endl;
    }
    else
    {
        this->_window = SDL_CreateWindow("SDL Tutorial",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SCREEN_WIDTH,
                                            SCREEN_HEIGHT,
                                            SDL_WINDOW_SHOWN);
        if (this->_window == NULL)
        {
            success = false;
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                std::cerr << "SDL_Image could not initialize! SDL_Image error: " << IMG_GetError() << std::endl;
                success = false;
            }
            else
                this->_screenSurface = SDL_GetWindowSurface(this->_window);
        }
    }
    return success;
}
