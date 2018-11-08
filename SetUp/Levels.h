#ifndef LOG_LEVELS_H
#define LOG_LEVELS_H

#include "Game.h"
#include "TextureManager.h"
#include "../War.h"

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
    War* war;

    bool start = false;
    const Uint8 *keyState;
    static int Level;
    static bool easy, medium, hard, next;
    static int attackenemy1, attackenemy2,attackenemy3, attackenemy4,attackenemy5, attackenemy6,attackenemy7, attackenemy8,attackenemy9, attackenemy10,
    attackenemy11, attackenemy12, attackenemy13, attackenemy14, attackenemy15, attackenemy16, attackenemy17, attackenemy18, attackenemy19, attackenemy20,
    attackenemy21, attackenemy22,attackenemy23, attackenemy24,attackenemy25, attackenemy26,attackenemy27, attackenemy28, attackenemy29, attackenemy30,
    attackenemy31, attackenemy32, attackenemy33, attackenemy34, attackenemy35, attackenemy36;

    static int lifeenemy1, lifeenemy2,lifeenemy3, lifeenemy4,lifeenemy5, lifeenemy6,lifeenemy7, lifeenemy8,lifeenemy9, lifeenemy10,
            lifeenemy11, lifeenemy12, lifeenemy13, lifeenemy14, lifeenemy15, lifeenemy16, lifeenemy17, lifeenemy18, lifeenemy19, lifeenemy20,
            lifeenemy21, lifeenemy22,lifeenemy23, lifeenemy24,lifeenemy25, lifeenemy26,lifeenemy27, lifeenemy28, lifeenemy29, lifeenemy30,
            lifeenemy31, lifeenemy32, lifeenemy33, lifeenemy34, lifeenemy35, lifeenemy36;
};


#endif //LOG_LEVELS_H
