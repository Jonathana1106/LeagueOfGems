#include "TextureManager.h"
#include "Game.h"

SDL_Texture *TextureManager::LoadTexture(const char *filename) {
    SDL_Surface *surface = SDL_LoadBMP(filename);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);

    return tex;
}

void TextureManager::Draw(SDL_Texture *text, SDL_Rect pos) {
    SDL_RenderCopy(Game::renderer, text, NULL, &pos);
}
