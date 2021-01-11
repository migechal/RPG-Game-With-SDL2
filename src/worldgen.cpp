#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include "../headers/worldgen.h"

SDL_Texture* wrgen::loadTexture(char* path, SDL_Renderer* Renderer){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}


int wrgen::createRenderer(SDL_Renderer* Renderer, SDL_Window* Window){
    Renderer = SDL_CreateRenderer(Window, -1, 0);
    if(Renderer){
        return 0;
    }
    else{
        std::cout << "Error in the creation of the renderer. Error is:  "<< SDL_GetError << std::endl;
        return -1;
    }
}

int wrgen::createTexture(SDL_Renderer* Renderer, SDL_Texture* texture, char* path){
    texture = loadTexture(path, Renderer);
    if(texture){
        return 0;
    }
    else{
        std::cout<<"Failed to load images properly." << std::endl;
        return -1;
    }
}

wrgen::World::World(SDL_Texture* worldTexture, SDL_Rect CenterScreen){
    WorldText = worldTexture;
    centerScreen = CenterScreen;
}

char* wrgen::World::checkChunk(SDL_Rect playerPosition){
    if(playerPosition.x - centerScreen.x >= edgex){
        return (char*)'r';
    }
    else if (playerPosition.x - centerScreen.x <= -edgex)
    {
        return (char*)'l';
    }
    else if(playerPosition.y - centerScreen.y >= edgey){
        return (char*)'d';
    }
    else if (playerPosition.y - centerScreen.y <= -edgey)
    {
        return (char*)'u';
    }
}