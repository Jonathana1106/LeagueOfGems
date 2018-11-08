#include "player.h"
#include "../SetUp/TextureManager.h"
#include "../SetUp/Game.h"
#include "../SetUp/Levels.h"

using namespace std;

void player::init(int posX, int posY) {

    position.h = position.w = 35;
    position.x = x = posX;
    position.y = y = posY;
    p.second = posX / 35;
    p.first = posY /35;
    contX = contY = 0;
    stat = TextureManager::LoadTexture("../Assets/static.bmp");
    right1 = TextureManager::LoadTexture("../Assets/right1.bmp");
    right2 = TextureManager::LoadTexture("../Assets/right2.bmp");
    right3 = TextureManager::LoadTexture("../Assets/right3.bmp");
    left1 = TextureManager::LoadTexture("../Assets/left1.bmp");
    left2 = TextureManager::LoadTexture("../Assets/left2.bmp");
    left3 = TextureManager::LoadTexture("../Assets/left3.bmp");
    up1 = TextureManager::LoadTexture("../Assets/up1.bmp");
    up2 = TextureManager::LoadTexture("../Assets/up2.bmp");
    up3 = TextureManager::LoadTexture("../Assets/up3.bmp");
    up4 = TextureManager::LoadTexture("../Assets/up4.bmp");
    map = new Map();
    pathfinding = new Pathfinding();
}

void player::move() {

    if (position.x < p.second * 35) {
        contX++;
        left = up = down = 0;
        right++;
        leftB = upB = downB = false;
        rightB = true;
        if (contX % 1 == 0) {
            position.x++;
        }
    }

    if (position.x > p.second * 35) {
        contX++;
        right = up = down = 0;
        left++;
        rightB = upB = downB = false;
        leftB = true;
        if (contX % 1 == 0) {
            position.x--;
        }
    }

    if (position.y < p.first * 35) {
        contY++;
        left = right = up = 0;
        down++;
        leftB = rightB = upB = false;
        downB = true;
        if (contY % 1 == 0) {
            position.y++;
        }
    }

    if (position.y > p.first * 35) {
        contY++;
        left = right = down = 0;
        up++;
        leftB = rightB = downB = false;
        upB = true;
        if (contY % 1 == 0) {
            position.y--;
        }
    }

    if(position.y == (y/35)*35 && position.x == (x/35)*35){
        rightB = leftB = upB = downB = false;
        right = left = up = down = 0;
    }
}

void player::render() {

    map->DrawMap();
    if(!rightB && !leftB && !upB && !downB) {
        //SDL_RenderCopy(Game::renderer, stat, NULL, &position);
    }else{
        animation();
    }
}

void player::animation() {
    if(rightB){
        if(right <= 5){
            SDL_RenderCopy(Game::renderer, right1, NULL, &position);
        }
        if(right > 5 && right <= 10){
            SDL_RenderCopy(Game::renderer, right2, NULL, &position);
        }
        if(right > 10 && right <=15){
            SDL_RenderCopy(Game::renderer, right3, NULL, &position);
        }
        if (right == 15){
            right = 0;
        }
    }
    if(leftB){
        if(left <= 5){
            SDL_RenderCopy(Game::renderer, left1, NULL, &position);
        }
        if(left > 5 && left <= 10){
            SDL_RenderCopy(Game::renderer, left2, NULL, &position);
        }
        if(left > 10 && left <=15){
            SDL_RenderCopy(Game::renderer, left3, NULL, &position);
        }
        if (left == 15){
            left = 0;
        }
    }
    if(upB){
        if(up <= 5){
            SDL_RenderCopy(Game::renderer, up1, NULL, &position);
        }
        if(up > 5 && up <= 10){
            SDL_RenderCopy(Game::renderer, up2, NULL, &position);
        }
        if(up > 10 && up <= 15){
            SDL_RenderCopy(Game::renderer, up3, NULL, &position);
        }
        if(up > 15 && up <= 20){
            SDL_RenderCopy(Game::renderer, up4, NULL, &position);
        }
        if (up == 20){
            up = 0;
        }
    }
    if(downB){
        if(down <= 5){
            SDL_RenderCopy(Game::renderer, stat, NULL, &position);
        }
        if(down > 5 && down <= 10){
            SDL_RenderCopy(Game::renderer, stat, NULL, &position);
        }
        if(down > 10 && down <= 15){
            SDL_RenderCopy(Game::renderer, stat, NULL, &position);
        }
        if(down > 15 && down <= 20){
            SDL_RenderCopy(Game::renderer, stat, NULL, &position);
        }
        if (down == 20){
            down = 0;
        }
    }
}

void player::getGem() {
    if(Levels::Level == 1 && ((position.x == 1190 && position.y == 490) || (position.x ==1225 && position.y == 455))){
        Levels::Level ++;
        Levels::next = true;
    }
    if(Levels::Level == 2 && ((position.x == 1190 && position.y == 0) || (position.x ==1225 && position.y == 35))){
        Levels::Level ++;
        Levels::next = true;
    }
    if(Levels::Level == 3 && ((position.x == 1190 && position.y == 210) || (position.x ==1225 && position.y == 245) || (position.x == 1225 && position.y == 175))){
        Levels::Level ++;
        Levels::next = true;
    }
    if(Levels::Level == 4 && ((position.x == 1190 && position.y == 245) || (position.x ==1225 && position.y == 280) || (position.x == 1225 && position.y == 210))){
        Levels::Level ++;
        Levels::next = true;
    }
}

void player::update() {

    if(contX > 1000000){
        contX = 0;
    }

    if(contY > 1000000){
        contY = 0;
    }

    SDL_PumpEvents();
    if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
        SDL_GetMouseState(&x, &y);
        if(y < 525) {
            if (Levels::Level == 1) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 2) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 3) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 4) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 5) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            }
        }
    }

    if(!path_destiny.empty()){
        p = path_destiny.top();
        if(position.x == p.second*35 && position.y == p.first*35){
            path_destiny.pop();
        }
    }

    getGem();
    detectEnemy();
}

void player::detectEnemy() {
    if(Map::map[position.y/35][(position.x + 35)/35] > 25 && Map::map[position.y/35][(position.x + 35)/35] < 73){

    }else if(Map::map[position.y/35][(position.x - 35)/35] > 25 && Map::map[position.y/35][(position.x - 35)/35] < 73){

    }else if(Map::map[(position.y - 35)/35][position.x/35] > 25 && Map::map[(position.y - 35)/35][position.x/35] < 73){

    }else if(Map::map[(position.y + 35)/35][position.x/35] > 25 && Map::map[(position.y + 35)/35][position.x/35] < 73){
        
    }
}
