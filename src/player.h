#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "math.h"

#define NUM_FRAME_PER_LINE 5
#define NUM_LINES 1

class Player{
    public:
        Player();
        ~Player();
        void Draw();
        bool Shoot();
        void Move();
        void Rotate();
        Rectangle GetRect();
        void SetActive(bool value);
        bool IsActive();
        float GetPlayerRotation();
        Vector2 GetPlayerPosition();
        Vector2 GetPlayerSpeed();
        void StartExplosion();
        bool IsExploding();
        void Update();

        
        
        
    private:
    Texture2D image;
    Vector2 position;
    Vector2 speed;
    float acceleration;
    float rotation;
    float scale;
    bool active;
    Sound bulletSound;
    float frameWidth;
    float frameHeight;
    Texture2D explosion;
    int currentFrame;
    int currentLine;
    Rectangle frameRec;
    Vector2 explosionPos;
    bool isExploding;
    float explosionTimer;
};


#endif 