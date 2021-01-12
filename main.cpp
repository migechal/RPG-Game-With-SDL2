#include "headers/game.h"
#include "headers/worldgen.h"
#include "headers/type.h"
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
int main(){
    SDL_Renderer*   grenderer;
    SDL_Window*     window;
    SDL_Texture*    background;
    Player          player;
    SDL_DisplayMode DM;

    if(!SDL_GetCurrentDisplayMode(0, &DM)){
        DM.w = 1920;
        DM.h = 1080;
    }

    window = SDL_CreateWindow("RPG Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.w, DM.h, SDL_WINDOW_SHOWN);

    background = wrgen::loadTexture((char*)"assets/", grenderer);

    return 0;
}
