#ifndef LOG_PLAYER_H
#define LOG_PLAYER_H

#include <iostream>
#include <SDL_mouse.h>
#include <SDL_events.h>
#include "SDL.h"
#include "../SetUp/Map.h"
#include "../Internal_logic/Pathfinding.h"

class player {

public:
    void init();
    void move();
    void render();
    int x, y;
    int contX, contY, reg;
    SDL_Rect position;
    SDL_Texture *user1, *user2, *user3;

    std::stack<Pair> path_destiny;
    std::pair<int, int> p;

    Map* map;
    Pathfinding *pathfinding;

};

#endif LOG_PLAYER_H