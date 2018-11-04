#include <iostream>
#include "Game.h"

int main() {

    Game *game = new Game;
    game->init("League of Gems", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 600);
    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}