#include "raylib.h"
#ifndef POWERUP_H
#define POWERUP_H

class PowerUp{
    public:
        PowerUp();
        ~PowerUp();
        void Update();
        void Draw();
        Rectangle GetRect();
        void GetType();


    private:
        Vector2 position;
        Texture2D image;
        bool status;
        int type;

};




#endif