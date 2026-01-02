#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "math.h"

class Player{
    public:
        Player();
        ~Player();
        void Draw();
        bool Shoot();
        void Move();
        void Rotate();
        void GetPlayerRotation();
        Vector2 GetPlayerPosition();
        
    private:
    Texture2D image;
    Vector2 position;
    Vector2 speed;
    float acceleration;
    float rotation;
    float scale;
};


#endif 