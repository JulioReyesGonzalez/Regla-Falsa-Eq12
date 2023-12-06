#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool initialize(SDL_Window* window);
    // Otros métodos de renderizado

private:
    SDL_Renderer* sdlRenderer;
};

#endif

