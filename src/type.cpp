#include"../headers/type.h"

Object::Object(std::string Type, int Id, int DamagePossible, int CriticalChance){
    Id_ = Id;
    Type_ = Type;
    DamagePossible_ = DamagePossible;
    CriticalChance_ = CriticalChance;
}
int Object::critchance(){
    return CriticalChance_;
}
int Object::damage(){
    return DamagePossible_;
}
int Object::id(){
    return Id_;
}
std::string Object::type(){
    return Type_;
}


Player::Player(){
    inventory.resize(5);
    for(int i = 0; i <= 100; i++){
        inventory[i] = 0;
    }
}
int Player::invCount(int location){
    return inventory[location];
}
int Player::giveObject(Object &object){
    int location = object.id();
    if(invCount(location) < 100){
        ++inventory[location];
        return location;
    }
    return -1;
}
