#ifndef LOG_LEVELS_H
#define LOG_LEVELS_H

#include "Game.h"
#include "TextureManager.h"

class Levels {

public:
    void welcome();
    void createLevel();
    void nextLevel(char *title);
    void createGame();
    void render();
    void draw();

    SDL_Window *window;
    SDL_Renderer *rend;
    SDL_Rect position;
    SDL_Texture *welc, *congrat, *stage;

    bool start = false;
    const Uint8 *keyState;
    static int Level;
    static bool easy, medium, hard, next;

};


#endif //LOG_LEVELS_H
