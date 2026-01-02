#include "player.h"



Player::Player()
{

    image = LoadTexture("build/SPRITES/PLAYER.png");
    position.x = (GetScreenWidth() - image.width)/ 2;
    position.y = (GetScreenHeight() - image.height) / 2;
    scale = 2.0;
    rotation = 0.0f;
    

    

}

Player::~Player(){
    UnloadTexture(image);

}

void Player::Draw(){
    
    Rectangle source = {0,0, (float)image.width, (float)image.height}; //set source image
    Rectangle dest = {position.x, position.y, image.width * scale, image.height * scale}; //scale
    Vector2 origin = {(image.width * scale) / 2, (image.height * scale)/2}; //rotate around center

    DrawTexturePro(image, source, dest, origin, rotation, WHITE);
}

void Player::Rotate(){

    //Player logic: rotation
    if(IsKeyDown(KEY_A)){
        rotation -= 5; 
    }
    if(IsKeyDown(KEY_D)){
        rotation += 5;
    }
}

void Player::Move(){
    //calculate speed
    speed.x = sin(rotation*DEG2RAD)*6.0f;
    speed.y = cos(rotation*DEG2RAD)*6.0f;

    //player logic: accelertaion
    if(IsKeyDown(KEY_W)){
        if(acceleration < 1){
            acceleration += 0.04f;
        }else{
            if(acceleration > 0){
                acceleration -=0.03f;
            }else if(acceleration < 0){
                acceleration = 0;
            }
        }
    }

    if(IsKeyDown(KEY_S)){
        if(acceleration > 0){
            acceleration -= 0.04;
        } else if(acceleration < 0) {
            acceleration = 0;
        }
    }

    //update position
    position.x += speed.x * acceleration;
    position.y -= speed.y * acceleration;
}

void Player::Shoot(){
    
}