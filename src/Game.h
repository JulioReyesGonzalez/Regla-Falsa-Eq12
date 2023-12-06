#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "Renderer.h"

class Game {
public:
    Game();
    ~Game();

    bool initialize();
    void run();
    void closeSDL();

private:
    SDL_Window* window;
    Renderer renderer;
};

#endif
