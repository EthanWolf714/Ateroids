#include "asteroid.h"


Asteroid::Asteroid(Vector2 startPos, Vector2 startSpeed, int asteroidSize, Texture2D* asteroidTexture){
    position = startPos;
    speed = startSpeed;
    active = true;
    size =  asteroidSize;
    image = asteroidTexture;
    
    //scale asteroid based on size
    if(size == 3){
        scale = 3.0f;
    }else if(size == 2){
        scale = 2.0f;
    }else if( size == 1){
        scale = 1.0f;
    }
}


Asteroid::~Asteroid(){
   
}

void Asteroid::Draw(){  
    DrawTextureEx(*image, position, 0, scale, WHITE);
    
    
}

void Asteroid::Update(){
    //asteroid velocity
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();

    float spriteWidth = image -> width * scale;
    float spriteHeight = image-> height * scale;

    //if asteroid floats off screen then move position to other side of screen
    if(position.x > GetScreenWidth() + spriteWidth){
        position.x = -spriteWidth;
    }
    if(position.x < -spriteWidth){
        position.x = GetScreenWidth() + spriteWidth;
    }
    if(position.y < -spriteHeight){
        position.y = GetScreenHeight() + spriteHeight;
    }
    if(position.y > GetScreenHeight() + spriteHeight){
        position.y = -spriteHeight;
    }

}

bool Asteroid::isActive(){
    return active;
}

Vector2 Asteroid::GetPosition(){
    return position;
}

int Asteroid::GetSize(){
    return size;
}

Rectangle Asteroid::GetRect(){
    return Rectangle{position.x, position.y, (float)image->width * scale, (float)image->height * scale};
}

void Asteroid::SetActive(bool value){
    active = value;
}
