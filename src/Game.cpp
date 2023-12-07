#include "../include/Game.h"
#include <iostream>

Game::Game() : window(nullptr), renderer() {}

Game::~Game() {
    closeSDL();
}

bool Game::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!renderer.initialize(window)) {
        return false;
    }

    return true;
}

void Game::run() {
    // Lógica del juego
}

void Game::closeSDL() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
