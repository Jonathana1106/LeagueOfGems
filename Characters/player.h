#ifndef LOG_PLAYER_H
#define LOG_PLAYER_H

#include <iostream>
#include <SDL_mouse.h>
#include <SDL_events.h>
#include "SDL.h"
#include "../SetUp/Map.h"

class player {

public:
    void init();
    void move();
    void render();
    int x, y;
    int contX, contY, reg;
    SDL_Rect position;
    SDL_Texture *user1, *user2, *user3;
    Map *map;


};

#endif LOG_PLAYER_H