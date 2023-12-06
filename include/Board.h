#pragma once

#include <vector>
#include "Piece.h"

class Board {
public:
    Board();

    void mergePieceIntoBoard(const Piece& piece);
    void clearLines();

private:
    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;

    std::vector<std::vector<int>> board;
};
