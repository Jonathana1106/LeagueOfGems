#include "SDL.h"
#include "Map.h"

#ifndef LOG_TEXTUREMANAGER_H
#define LOG_TEXTUREMANAGER_H


class TextureManager {

public:
    static SDL_Texture *LoadTexture(const char *filename);
    static void Draw(SDL_Texture *text, SDL_Rect pos);
    static void render(SDL_Renderer *ren, SDL_Texture *te, SDL_Rect p);
    Map *map;

};


#endif //LOG_TEXTUREMANAGER_H
