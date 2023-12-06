#pragma once

#include <SDL2/SDL.h>
#include "Piece.h"

class InputHandler {
public:
    InputHandler();

    void handleInput(Piece& currentPiece);

private:
    // Add any necessary member variables or methods
};
