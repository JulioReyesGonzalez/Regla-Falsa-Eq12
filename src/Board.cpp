#include "Board.h"
#include "Piece.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>

Board::Board() : board(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0)) {}

void Board::mergePieceIntoBoard(const Piece& piece) {
    // Merge piece into the board
}

void Board::clearLines() {
    // Clear completed lines
}
