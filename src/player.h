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
        Rectangle GetRect();
        void SetActive(bool value);
        bool IsActive();
        float GetPlayerRotation();
        Vector2 GetPlayerPosition();
        Vector2 GetPlayerSpeed();
        void StartExplosion();
        bool IsExploding();
        void Update();
        void AddLife();
        void ActivateShield();
        void Reset();
        

        
        
        
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
    bool isExploding;
    float explosionTimer;
    int explosionFrame;  // current frame (0-4)
    Vector2 explosionPos;
    Sound explosionSound;
    int lives;
    bool hasSheild;
};


#endif 