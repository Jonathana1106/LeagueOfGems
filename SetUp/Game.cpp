#include "Game.h"
#include "TextureManager.h"

SDL_Renderer* Game::renderer = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height) {

    player1 = new player;
    position.h = position.w = 180;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window1 = SDL_CreateWindow(title, xpos, ypos, width, height, NULL);
        renderer = SDL_CreateRenderer(window1, -1, 0);
        isRunning = true;
    }else{
        isRunning = false;
    }

    background = TextureManager::LoadTexture("../Assets/background.bmp");
    player1->init(140, 140);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    player1->update();
    player1->move();
}

void Game::render() {
    SDL_RenderClear(renderer);
    for(int i=0; i<8; i++){
        for(int j=0; j<3; j++){
            position.x = 175*i;
            position.y = 175*j;
            SDL_RenderCopy(renderer, background, NULL, &position);
        }
    }
    player1->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyTexture(background);
    SDL_DestroyWindow(window1);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}