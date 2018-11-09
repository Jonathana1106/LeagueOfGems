#include "Map.h"
#include "TextureManager.h"
#include "Levels.h"
#include <iostream>

using namespace std;

int Map::map[15][36] = {
        {100, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,  0,  1,  1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {100, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {100, 15, 15, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,  1,  0,  0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {100, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 26, 29,  0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {100, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 27, 30,  0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,  0,  1,  0,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 31, 36,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,  0, 32, 37,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  0,  1,  0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 33, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0,  1,  1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  0, 34,  0,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0,  0,  0},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 28, 35,  0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 40, 42, 45},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,  1,  0,  0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,  0, 43, 46},
        {  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,  0,  0,  0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41, 44,  9}};

Map::Map() {

    tree1 = TextureManager::LoadTexture("../Assets/tree1.bmp");
    tree2 = TextureManager::LoadTexture("../Assets/tree2.bmp");
    tree3 = TextureManager::LoadTexture("../Assets/tree3.bmp");
    home = TextureManager::LoadTexture("../Assets/Home.bmp");
    enemy = TextureManager::LoadTexture("../Assets/enemy.bmp");
    tower = TextureManager::LoadTexture("../Assets/tower.bmp");
    obstacule1 = TextureManager::LoadTexture("../Assets/static.bmp");
    position.h = position.w = 35;
    position.x = position.y = trees = 0;
    game = new Game;
    if(Levels::Level == 1){
        Gem = TextureManager::LoadTexture("../Assets/Gem1.bmp");
        if(Levels::easy) {
            LoadMap(lvl1E);
        }
        if(Levels::medium) {
            LoadMap(lvl1M);
        }
        if(Levels::hard) {
            LoadMap(lvl1H);
        }
    }else if(Levels::Level == 2){
        Gem = TextureManager::LoadTexture("../Assets/Gem2.bmp");
        if(Levels::easy) {
            LoadMap(lvl2E);
        }
        if(Levels::medium) {
            LoadMap(lvl2M);
        }
        if(Levels::hard) {
            LoadMap(lvl2H);
        }
    }else if(Levels::Level == 3){
        Gem = TextureManager::LoadTexture("../Assets/Gem3.bmp");
        if(Levels::easy) {
            LoadMap(lvl3E);
        }
        if(Levels::medium) {
            LoadMap(lvl3M);
        }
        if(Levels::hard) {
            LoadMap(lvl3H);
        }
    }else if(Levels::Level == 4){
        Gem = TextureManager::LoadTexture("../Assets/Gem4.bmp");
        if(Levels::easy) {
            LoadMap(lvl4E);
        }
        if(Levels::medium) {
            LoadMap(lvl4M);
        }
        if(Levels::hard) {
            LoadMap(lvl4H);
        }
    }else if(Levels::Level == 5){
        Gem = TextureManager::LoadTexture("../Assets/Gem5.bmp");
        if(Levels::easy) {
            LoadMap(lvl5E);
        }
        if(Levels::medium) {
            LoadMap(lvl5M);
        }
        if(Levels::hard) {
            LoadMap(lvl5H);
        }
    }else{
        Gem = TextureManager::LoadTexture("../Assets/Gem6.bmp");
        if(Levels::easy) {
            LoadMap(lvl6E);
        }
        if(Levels::medium) {
            LoadMap(lvl6M);
        }
        if(Levels::hard) {
            LoadMap(lvl6H);
        }
    }
}

void Map::LoadMap(int arr[15][36]) {

    for(int row = 0; row < 15; row++){
        for( int column = 0; column < 36; column++){
            map[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap() {

    int type = 0;
    for (int row = 0; row < 15; row++) {
        for (int column = 0; column < 36; column++) {

            type = Map::map[row][column];
            position.x = column * 35;
            position.y = row * 35;
            switch (type) {
                case 1:
                    TextureManager::Draw(tree1, position);
                    break;
                case 3:
                    TextureManager::Draw(tower, position);
                    break;
                case 9:
                    TextureManager::Draw(Gem, position);
                    break;
                case 26 ... 62:
                    TextureManager::Draw(enemy, position);
                    break;
                case 10 ... 25:
                        //game->createSoldiers(type, position.x, position.y);

                    break;
                case 100:
                    position.w = 45;
                    TextureManager::Draw(home, position);
                    position.w = 35;
                default:
                    break;
            }
        }
    }
    reg = 1;
}