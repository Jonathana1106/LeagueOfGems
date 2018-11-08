#ifndef LOG_GAME_H
#define LOG_GAME_H

#include <iostream>
#include "SDL2/SDL.h"
#include <SDL_video.h>
#include <SDL_image.h>
#include "../Characters/player.h"
#include "Map.h"
#include "TextureManager.h"

using namespace std;

class Game {

public:
    void init(const char* title, int xpos, int ypos, int width, int height);
    void handleEvents();
    void update();
    void render();
    void clean();
    void createSoldiers();
    bool running(){return isRunning;};
    bool isRunning;
    SDL_Window *window1;
    static SDL_Renderer *renderer;
    SDL_Texture *background;
    SDL_Rect position;
    player *player1, *player2, *player3, *player4, *player5, *player6, *player7, *player8, *player9, *player10, *player11, *player12,
    *player13, *player14, *player15;
    Map *map;
    TextureManager *textureManager;

};

#endif //LOG_GAME_H
