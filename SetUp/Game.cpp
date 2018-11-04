#include "Game.h"
#include "TextureManager.h"

SDL_Renderer* Game::renderer = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
    player1 = new player;
    //map = new Map();
    position1.w = position1.h = position2.w = position2.h = position3.w = position5.w = position5.h = position6.w = position6.h =
    position7.w = position9.w = position9.h = position10.w = position10.h = position11.w = position13.w = position13.h =
    position14.w = position14.h = position15.w = position17.w = position17.h = position18.w = position18.h = position19.w =
    position21.w = position21.h = position22.w = position22.h = position23.w = position25.w = position25.h = position26.w =
    position26.h = position27.w = position29.w = position29.h = position30.w = position30.h = position31.w = 180;
    position1.x = position1.y = position2.x = position3.x = position5.y = position9.y = position13.y =
    position17.y = position21.y = position25.y = position29.y = 0;
    position2.y = position5.x = position6.x = position6.y = position7.x = position10.y = position14.y = position18.y
    = position22.y = position26.y = position30.y = position3.h = position7.h = position11.h = position15.h =
    position19.h = position23.h = position27.h = position31.h = 175;
    position3.y = position7.y = position9.x = position10.x = position11.x = position11.y = position15.y =
    position19.y = position23.y = position27.y = position31.y = 350;
    position13.x = position14.x = position15.x = 525;
    position17.x = position18.x = position19.x = 700;
    position21.x = position22.x = position23.x = 875;
    position25.x = position26.x = position27.x = 1050;
    position29.x = position30.x = position31.x = 1225;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "Subsystems Initialised!...\n";
        window1 = SDL_CreateWindow(title, xpos, ypos, width, height, NULL);
        if(window1){
            cout << "Window created!\n";
        }

        renderer = SDL_CreateRenderer(window1, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created!\n";
        }

        isRunning = true;
    }else{
        isRunning = false;
    }

    background = TextureManager::LoadTexture("../Assets/background.bmp");
    player1->init();
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
    player1->move();

}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, &position1);
    SDL_RenderCopy(renderer, background, NULL, &position2);
    SDL_RenderCopy(renderer, background, NULL, &position3);
    SDL_RenderCopy(renderer, background, NULL, &position5);
    SDL_RenderCopy(renderer, background, NULL, &position6);
    SDL_RenderCopy(renderer, background, NULL, &position7);
    SDL_RenderCopy(renderer, background, NULL, &position9);
    SDL_RenderCopy(renderer, background, NULL, &position10);
    SDL_RenderCopy(renderer, background, NULL, &position11);
    SDL_RenderCopy(renderer, background, NULL, &position13);
    SDL_RenderCopy(renderer, background, NULL, &position14);
    SDL_RenderCopy(renderer, background, NULL, &position15);
    SDL_RenderCopy(renderer, background, NULL, &position17);
    SDL_RenderCopy(renderer, background, NULL, &position18);
    SDL_RenderCopy(renderer, background, NULL, &position19);
    SDL_RenderCopy(renderer, background, NULL, &position21);
    SDL_RenderCopy(renderer, background, NULL, &position22);
    SDL_RenderCopy(renderer, background, NULL, &position23);
    SDL_RenderCopy(renderer, background, NULL, &position25);
    SDL_RenderCopy(renderer, background, NULL, &position26);
    SDL_RenderCopy(renderer, background, NULL, &position27);
    SDL_RenderCopy(renderer, background, NULL, &position29);
    SDL_RenderCopy(renderer, background, NULL, &position30);
    SDL_RenderCopy(renderer, background, NULL, &position31);
    player1->render();
  //  map->DrawMap();
    SDL_RenderPresent(renderer);

}

void Game::clean() {
    SDL_DestroyTexture(background);
    SDL_DestroyWindow(window1);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Cleaned\n";
}