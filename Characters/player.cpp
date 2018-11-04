#include "player.h"
#include "../SetUp/TextureManager.h"
#include "../SetUp/Game.h"

using namespace std;

void player::init() {
    position.h = position.w = position.x = position.y = x = y = 35;
    contX = contY = reg = 0;
    user1 = TextureManager::LoadTexture("../Assets/warrior1.bmp");
    user2 = TextureManager::LoadTexture("../Assets/warrior2.bmp");
    user3 = TextureManager::LoadTexture("../Assets/warrior3.bmp");
    map = new Map();

}

void player::move() {

    if(contX > 1000000){
        contX = 0;
    }

    if(contY > 1000000){
        contY = 0;
    }

    SDL_PumpEvents();
    if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
        SDL_GetMouseState(&x, &y);
    }

    if (position.x < x){
        contX ++;
        if(contX % 3 == 0) {
            position.x ++;
        }
    }

    if (position.x > x){
        contX ++;
        if(contX % 3 == 0) {
            position.x --;
         }
    }

    if (position.y < y){
        contY ++;
        if(contY % 3 == 0) {
            position.y ++;
        }
    }

    if (position.y > y){
        contY ++;
        if(contY % 3 == 0) {
            position.y --;
        }
    }
}

void player::render() {
    map->DrawMap();
    SDL_RenderCopy(Game::renderer, user1, NULL, &position);

}