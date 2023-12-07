#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define SCREEN_WIDTH 303
#define SCREEN_HEIGHT 600
#define BLOCK_SIZE 30
#define BORDER_SIZE 2

SDL_Window* window;
SDL_Renderer* renderer;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

std::vector<std::vector<int>> board(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));

struct Tetromino {
    int x, y;
    std::vector<std::vector<int>> shape;
    SDL_Color color;

    void rotate() {
        std::vector<std::vector<int>> newShape(shape[0].size(), std::vector<int>(shape.size(), 0));
        for (size_t i = 0; i < shape.size(); ++i) {
            for (size_t j = 0; j < shape[i].size(); ++j) {
                newShape[j][i] = shape[i][j];
            }
        }
        for (size_t i = 0; i < newShape.size(); ++i) {
            std::reverse(newShape[i].begin(), newShape[i].end());
        }
        shape = newShape;
    }
};

Tetromino currentPiece;

bool initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        SDL_Log("Error creating window: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Error creating renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void closeSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawBlock(int x, int y, const SDL_Color& color) {
    SDL_Rect blockRect = {x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &blockRect);
}

void drawBoard() {
    // Dibuja el fondo negro
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Dibuja el límite del tablero como una delgada línea blanca
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect boardRect = {0, 0, BOARD_WIDTH * BLOCK_SIZE + BORDER_SIZE, BOARD_HEIGHT * BLOCK_SIZE + BORDER_SIZE};
    SDL_RenderDrawRect(renderer, &boardRect);

    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (board[i][j] != 0) {
                drawBlock(j, i, currentPiece.color);
            }
        }
    }
}

void drawCurrentPiece() {
    for (size_t i = 0; i < currentPiece.shape.size(); ++i) {
        for (size_t j = 0; j < currentPiece.shape[i].size(); ++j) {
            if (currentPiece.shape[i][j] != 0) {
                drawBlock(currentPiece.x + j, currentPiece.y + i, currentPiece.color);
            }
        }
    }
}

bool isValidMove(const Tetromino& piece, int offsetX, int offsetY) {
    for (size_t i = 0; i < piece.shape.size(); ++i) {
        for (size_t j = 0; j < piece.shape[i].size(); ++j) {
            if (piece.shape[i][j] != 0) {
                int newX = piece.x + j + offsetX;
                int newY = piece.y + i + offsetY;

                if (newX < 0 || newX >= BOARD_WIDTH || newY >= BOARD_HEIGHT) {
                    return false;
                }

                if (newY >= 0 && board[newY][newX] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void mergePieceIntoBoard(const Tetromino& piece) {
    for (size_t i = 0; i < piece.shape.size(); ++i) {
        for (size_t j = 0; j < piece.shape[i].size(); ++j) {
            if (piece.shape[i][j] != 0) {
                int boardX = piece.x + j;
                int boardY = piece.y + i;
                board[boardY][boardX] = 1;
            }
        }
    }
}

void spawnPiece() {
    const std::vector<std::vector<int>> shapes[7] = {
        {{1, 1, 1, 1}},           
        {{1, 1, 1, 0}, {1, 0, 0, 0}},  
        {{1, 1, 1, 0}, {0, 0, 1, 0}},  
        {{1, 1}, {1, 1}},              
        {{0, 1, 1, 1}, {1, 1, 0, 0}},  
        {{1, 1, 1, 0}, {0, 1, 0, 0}},  
        {{1, 1, 0, 0}, {0, 1, 1, 0}}   
    };

    currentPiece.shape = shapes[rand() % 7];
    currentPiece.x = BOARD_WIDTH / 2 - currentPiece.shape[0].size() / 2;
    currentPiece.y = 0;
    currentPiece.color = {static_cast<Uint8>(rand() % 256),
                          static_cast<Uint8>(rand() % 256),
                          static_cast<Uint8>(rand() % 256), 255};
}

void clearLines() {
    for (int i = BOARD_HEIGHT - 1; i >= 0; --i) {
        bool lineComplete = true;
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (board[i][j] == 0) {
                lineComplete = false;
                break;
            }
        }

        if (lineComplete) {
            for (int k = i; k > 0; --k) {
                for (int j = 0; j < BOARD_WIDTH; ++j) {
                    board[k][j] = board[k - 1][j];
                }
            }
            for (int j = 0; j < BOARD_WIDTH; ++j) {
                board[0][j] = 0;
            }
        }
    }
}

void update() {
    if (isValidMove(currentPiece, 0, 1)) {
        currentPiece.y += 1;
    } else {
        mergePieceIntoBoard(currentPiece);
        clearLines();
        spawnPiece();
    }
}

void render() {
    drawBoard();
    drawCurrentPiece();
    SDL_RenderPresent(renderer);
}

void handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                closeSDL();
                exit(0);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (isValidMove(currentPiece, -1, 0)) {
                            currentPiece.x -= 1;
                        }
                        break;
                    case SDLK_RIGHT:
                        if (isValidMove(currentPiece, 1, 0)) {
                            currentPiece.x += 1;
                        }
                        break;
                    case SDLK_DOWN:
                        if (isValidMove(currentPiece, 0, 1)) {
                            currentPiece.y += 1;
                        }
                        break;
                    case SDLK_UP:
                        Tetromino rotatedPiece = currentPiece;
                        rotatedPiece.rotate();
                        if (isValidMove(rotatedPiece, 0, 0)) {
                            currentPiece = rotatedPiece;
                        }
                        break;
                }
                break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (!initialize()) {
        return 1;
    }

    spawnPiece();

    while (true) {
        handleInput();
        update();
        render();
        SDL_Delay(500);
    }

    closeSDL();
    return 0;
}
