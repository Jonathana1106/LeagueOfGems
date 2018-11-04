#ifndef LOG_MAP_H
#define LOG_MAP_H

#include "SDL.h"

class Map {

public:

    Map();
    ~Map();

    void LoadMap(int[15][36]);
    void DrawMap();

public:

    SDL_Texture* tree1;
    SDL_Rect position;

    int map[15][36];

};


#endif //LOG_MAP_H
