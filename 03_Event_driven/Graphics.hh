#ifndef GRAPHICS_HH_
# define GRAPHICS_HH_

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Graphics {
    public:
        Graphics(void);
        ~Graphics(void);
    private:
        Graphics(const Graphics& obj);
        const Graphics& operator=(const Graphics& obj);
    private:
        SDL_Window  *_window;
        SDL_Surface *_screenSurface;
    public:
        SDL_Surface*    getScreenSurface(void) const;
        SDL_Window*     getWindow(void) const;
        bool            init(void);
        bool            loadMedia(const char* pathToFile, SDL_Surface **imgSurface);
};

#endif /* !GRAPHICS_HH_*/
