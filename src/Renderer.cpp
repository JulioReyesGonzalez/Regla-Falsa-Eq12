#include "Renderer.h"
#include <iostream>

Renderer::Renderer() : sdlRenderer(nullptr) {}

Renderer::~Renderer() {
    // Asegúrate de liberar recursos aquí si es necesario
}

bool Renderer::initialize(SDL_Window* window) {
    sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!sdlRenderer) {
        std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    // Configuración adicional del renderer si es necesario

    return true;
}

// Implementa otros métodos de renderizado según sea necesario
