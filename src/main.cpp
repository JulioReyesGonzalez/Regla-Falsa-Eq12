#include "../include/Game.h"
#include <iostream>
int main(int argc, char** argv) {
    Game game;

    if (!game.initialize()) {
        return 1;
    }

    game.run();
     game.closeSDL();

    return 0;
}
