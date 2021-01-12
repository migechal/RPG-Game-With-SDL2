#pragma once
#include <vector>
#include <string>
#include <SDL2/SDL.h>

class Object{
    int Id_;
    std::string Type_;
    int DamagePossible_;
    int CriticalChance_;
public:
    Object(std::string Type, int Id, int DamagePossible, int CriticalChance);
    int damage();
    int critchance();
    int id();
    std::string type();
};


class Player{
    std::vector<int>inventory;
    int invCount(int location);
public:
    Player();
    int giveObject(Object &object);
    SDL_Rect pos;
    SDL_Texture* playerSurface;
};