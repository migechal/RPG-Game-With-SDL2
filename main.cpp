#include "headers/game.h"
#include "headers/worldgen.h"
#include "headers/type.h"
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
int main(){
    SDL_Renderer*   renderer;
    SDL_Window*     window;
    SDL_Texture*    background;
    Player          player;
    SDL_DisplayMode DM;

    SDL_GetCurrentDisplayMode(0, &DM);

    window = SDL_CreateWindow("RPG Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.w, DM.h, SDL_WINDOW_SHOWN);

    background = wrgen::loadTexture("assets/", renderer);

    return 0;
}
