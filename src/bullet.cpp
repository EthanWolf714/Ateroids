#include "bullet.h"
#include "player.h"

Bullet::Bullet(Vector2 startPos, Vector2 startSpeed, Texture2D* bulletTexture) {
    position = startPos;
    speed = startSpeed;
    image = bulletTexture;
    lifetime = 2.0f;
    active = true;
}

Bullet::~Bullet(){

}

void Bullet::Draw(){
    if(active){
        DrawTextureV(*image, position, WHITE);
    }
}


void Bullet::Update(){
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();

    lifetime -= GetFrameTime();

    if(lifetime <= 0){
        active = false;
    }
}

bool Bullet::IsActive(){
    return active;
}

Vector2 Bullet::GetPosition(){
    return position;
}