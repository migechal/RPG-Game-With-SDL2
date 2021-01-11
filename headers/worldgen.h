#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>

namespace wrgen{
    SDL_Texture* loadTexture(char* path, SDL_Renderer* Rendere);
    int createRenderer(SDL_Renderer* Renderer, SDL_Window* Window);
    int createTexture(SDL_Renderer* Renderer, SDL_Texture* texture, char* path);
    class World{
        const int chuckSizeX = 3840;
        const int chuckSizeY = 2160;
        const int edgex = 200;
        const int edgey = 100;
        int startx, starty, endx, endy;
        SDL_Rect savedPos;
        SDL_Rect centerScreen;
        SDL_Texture* WorldText;
    public:
        World(SDL_Texture* worldTexture, SDL_Rect CenterScreen);
        int load(int startx, int endx, int starty, int endy);
        char* checkChunk(SDL_Rect playerPosition);
        int savePos();
    };
    class Sound{
        std::vector<char*> soundFiles;
        std::vector<Mix_Chunk*> soundMount;
    public:
        int addAudioFiles(char* fileName);
        int openAudioChannel();
        int allocateAudioChannel();
        int mountAudios();
        int playMusic(char* fileName);
    };
}