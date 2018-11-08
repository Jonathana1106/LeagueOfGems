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
    SDL_Rect position;
    player *player1, *player2;
    Map *map;
};

#endif //LOG_GAME_H
