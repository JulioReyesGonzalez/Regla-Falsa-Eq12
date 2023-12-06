#pragma once

#include <vector>
#include <SDL2/SDL.h>

class Piece {
public:
    Piece();

    void rotate();

private:
    int x, y;
    std::vector<std::vector<int>> shape;
    SDL_Color color;
};
