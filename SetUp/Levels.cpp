#include "Levels.h"
//#include <SDL_ttf.h>
//#include <SDL_opengles2_gl2.h>

int Levels::Level = 6;
bool Levels::easy = false;
bool Levels::medium = false;
bool Levels::hard = false;
bool Levels::next = false;

void Levels::welcome() {

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Welcome", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 300, NULL);
    rend = SDL_CreateRenderer(window, -1, 0);
    position.x = position.y = 0;
    position.h = 300;
    position.w = 500;
    welc = TextureManager::LoadTexture("../Assets/Kvothe.bmp");
    keyState = SDL_GetKeyboardState(NULL);
    while (!start) {
        SDL_PumpEvents();
        if (keyState[SDL_SCANCODE_E]) {
            start = true;
            easy = true;
        }
        if (keyState[SDL_SCANCODE_M]) {
            start = true;
            medium = true;
        }
        if (keyState[SDL_SCANCODE_H]) {
            start = true;
            hard = true;
        }
        if (start) {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(rend);
            createLevel();
        }
        render();
    }
}

void Levels::createLevel() {

    if (Level == 1) {
        if(easy){
            War* war = War::getInstance(20, 15, 1);
        }else if(medium){
            War* war = War::getInstance(26, 15, 2);
        } else if(hard){
            War* war = War::getInstance(36, 15, 3);
        }
        nextLevel("First Level");
        createGame();
    }
    if (Level == 2) {

        next = false;
        nextLevel("Second Level");
        createGame();
    }
    if (Level == 3) {
        next = false;
        nextLevel("Third Level");
        createGame();
    }
    if (Level == 4) {
        next = false;
        nextLevel("Fourth Level");
        createGame();
    }
    if (Level == 5) {
        next = false;
        nextLevel("Fifth Level");
        createGame();
    }
    if (Level == 6) {
        next = false;
        nextLevel("Sixth Level");
        createGame();
        //fin del juego
    }
}

void Levels::nextLevel(char *title) {

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 300, NULL);
    rend = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderClear(rend);
    if (Level == 1) {
        stage = TextureManager::LoadTexture("../Assets/stage1.bmp");
        SDL_RenderCopy(rend, stage, NULL, &position);
    } else if (Level == 2) {
        stage = TextureManager::LoadTexture("../Assets/stage2.bmp");
        SDL_RenderCopy(rend, stage, NULL, &position);
    } else if (Level == 3) {
        stage = TextureManager::LoadTexture("../Assets/stage3.bmp");
        SDL_RenderCopy(rend, stage, NULL, &position);
    } else if (Level == 4) {
        stage = TextureManager::LoadTexture("../Assets/stage4.bmp");
        SDL_RenderCopy(rend, stage, NULL, &position);
    } else if (Level == 5) {
        stage = TextureManager::LoadTexture("../Assets/stage5.bmp");
        SDL_RenderCopy(rend, stage, NULL, &position);
    } else {
        stage = TextureManager::LoadTexture("../Assets/stage6.bmp");
        SDL_RenderCopy(rend, stage, NULL, &position);
    }
    SDL_RenderPresent(rend);
    SDL_Delay(2000);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
}

void Levels::createGame() {
    Game *game = new Game;
    game->init("League of Gems", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 600);
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
        if (next) {
            break;
        }
    }

    game->clean();
}

void Levels::render() {

    SDL_RenderClear(rend);
    TextureManager::render(rend, welc, position);
    SDL_RenderPresent(rend);
}