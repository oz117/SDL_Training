#include "Graphics.hh"

/*
 * initializes the two pointer attributes to NULL (window and it's surface)
 */
Graphics::Graphics(void)
{
    this->_window = NULL;
    this->_renderer = NULL;
}

/*
 * Destroy the window properly and resets the pointer to NULL
 */
Graphics::~Graphics()
{
    SDL_DestroyRenderer(this->_renderer);
    this->_renderer = NULL;
    SDL_DestroyWindow(this->_window);
    this->_window = NULL;
    SDL_Quit();
}

SDL_Renderer*    Graphics::getRenderer(void) const
{
    return this->_renderer;
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
            this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
            if (this->_renderer == NULL)
            {
                success = false;
                std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
            }
            else
            {
                SDL_SetRenderDrawColor(this->_renderer, 255, 0, 0, 255);
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cerr << "SDL_Image could not initialize! SDL_Image error: " << IMG_GetError() << std::endl;
                    success = false;
                }
            }
        }
    }
    return success;
}
