#ifndef LOG_PLAYER_H
#define LOG_PLAYER_H

#include <iostream>
#include <SDL_mouse.h>
#include <SDL_events.h>
#include "SDL.h"
#include "../SetUp/Map.h"
#include "../InternalLogic/Pathfinding.h"

class player {

public:
    void init(int posX, int posY, int ID);
    void move();
    void render();
    void animation();
    void getGem();
    void update();
    void detectEnemy();
    void attack();
    void threadRender();
    void killEnemy();

    int x, y, contX, contY, right, left, up, down, enemy, attackLeft, attackRight, id;
    SDL_Rect position;
    SDL_Texture *stat, *right1, *right2, *right3, *left1, *left2, *left3, *up1, *up2, *up3, *up4, *down1, *down2, *down3, *attackL1,
    *attackL2, *attackL3, *attackR1, *attackR2, *attackR3;
    bool rightB, leftB, upB, downB, attackR, attackL, isattacking;

    std::stack<Pair> path_destiny;
    std::pair<int, int> p;

    Map* map;
    Pathfinding *pathfinding;

};

#endif LOG_PLAYER_H