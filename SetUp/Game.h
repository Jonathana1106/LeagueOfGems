#ifndef LOG_GAME_H
#define LOG_GAME_H

#include <iostream>
#include "SDL2/SDL.h"
#include <SDL_video.h>
#include <SDL_image.h>
#include "../Characters/player.h"
#include "Map.h"

using namespace std;

class Game {

public:
    void init(const char* title, int xpos, int ypos, int width, int height);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running(){return isRunning;};
    bool isRunning;
    SDL_Window *window1;
    static SDL_Renderer *renderer;
    SDL_Texture *background;
    SDL_Rect position1, position2, position3, position5, position6, position7, position9, position10, position11, position13,
    position14, position15, position17, position18, position19, position21, position22, position23,  position25, position26,
    position27, position29, position30, position31;
    player *player1;
    Map *map;

};

#endif //LOG_GAME_H
