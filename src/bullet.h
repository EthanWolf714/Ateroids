#ifndef BULLET_H
#define BULLET_H
#include "raylib.h"
#include "math.h"

class Bullet{
    public:
        Bullet(Vector2 startPos, Vector2 startSpeed, Texture2D* bulletTexture);
        ~Bullet();
        void Draw();
        void Update();
        bool IsActive();
        Vector2 GetPosition();
        
    private:
        Vector2 position;
        Vector2 speed;
        Texture2D* image;
        float lifetime;
        bool active;


};



#endif