#include "Game.h"
#include "TextureManager.h"

SDL_Renderer* Game::renderer = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
    player1 = new player;
    player2 = new player;
    player3 = new player;
    player4 = new player;
    player5 = new player;
    player6 = new player;
    player7 = new player;
    player8 = new player;
    player9 = new player;
    player10 = new player;
    player11 = new player;
    player12 = new player;
    player13 = new player;
    player14 = new player;
    player15 = new player;
    position.h = position.w = 180;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window1 = SDL_CreateWindow(title, xpos, ypos, width, height, NULL);
        renderer = SDL_CreateRenderer(window1, -1, 0);
        isRunning = true;
    }else{
        isRunning = false;
    }

    background = TextureManager::LoadTexture("../Assets/background.bmp");
    player1->init(70, 0);
    player2->init(70, 35);
    player3->init(70, 70);
    player4->init(70, 105);
    player5->init(70, 140);
    player6->init(105, 0);
    player7->init(105, 35);
    player8->init(105, 70);
    player9->init(105, 105);
    player10->init(105, 140);
    player11->init(140, 0);
    player12->init(140, 35);
    player13->init(140, 70);
    player14->init(140, 105);
    player15->init(140, 140);
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
    player2->update();
    player2->move();
    player3->update();
    player3->move();
    player4->update();
    player4->move();
    player5->update();
    player5->move();
    player6->update();
    player6->move();
    player7->update();
    player7->move();
    player8->update();
    player8->move();
    player9->update();
    player9->move();
    player10->update();
    player10->move();
    player11->update();
    player11->move();
    player12->update();
    player12->move();
    player13->update();
    player13->move();
    player14->update();
    player14->move();
    player15->update();
    player15->move();

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
    player2->render();
    player3->render();
    player4->render();
    player5->render();
    player6->render();
    player7->render();
    player8->render();
    player9->render();
    player10->render();
    player11->render();
    player12->render();
    player13->render();
    player14->render();
    player15->render();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyTexture(background);
    SDL_DestroyWindow(window1);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::createSoldiers() {
    int type = 0;
    for (int row = 0; row < 15; row++) {
        for (int column = 0; column < 36; column++) {

            type = Map::map[row][column];
            switch (type) {
                case 10:
                    //player1->init(column * 35 , row * 35);
                    break;
                case 11:
                    player2->init(column * 35 , row * 35);
                    break;
                case 12:
                    player3->init(column * 35 , row * 35);
                    break;
                case 13:
                    player4->init(column * 35 , row * 35);
                    break;
                case 14:
                    player5->init(column * 35 , row * 35);
                    break;
                case 15:
                    player6->init(column * 35 , row * 35);
                    break;
                case 16:
                    player7->init(column * 35 , row * 35);
                    break;
                case 17:
                    player8->init(column * 35 , row * 35);
                    break;
                case 18:
                    player9->init(column * 35 , row * 35);
                    break;
                case 19:
                    player10->init(column * 35 , row * 35);
                    break;
                case 20:
                    player11->init(column * 35 , row * 35);
                    break;
                case 21:
                    player12->init(column * 35 , row * 35);
                    break;
                case 22:
                    player13->init(column * 35 , row * 35);
                    break;
                case 23:
                    player14->init(column * 35 , row * 35);
                    break;
                case 24:
                    player15->init(column * 35 , row * 35);
                    break;
            }
        }
    }
}