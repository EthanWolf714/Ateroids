#include "player.h"



Player::Player()
{

    image = LoadTexture("build/SPRITES/PLAYER.png");
    position.x = (GetScreenWidth() - image.width)/ 2;
    position.y = (GetScreenHeight() - image.height) / 2;
    scale = 2.0;
    rotation = 0.0f;
    active = true;
    bulletSound = LoadSound("build/SFX/BULLET_1.wav");
     explosion = LoadTexture("build/SPRITES/EXPLOSION.png");
    frameHeight = (float)(explosion.height/NUM_FRAME_PER_LINE);
    frameWidth = (float)(explosion.width/NUM_LINES);
    currentFrame = 0;
    currentLine = 0;
   
    
    frameRec = {0,0, frameWidth, frameHeight};
    explosionPos = position;

    isExploding = false;
    explosionTimer = 0.0f;

    

    

}

Player::~Player(){
    UnloadTexture(image);

}

void Player::Update(){
     if(isExploding){
        TraceLog(LOG_INFO, "Exploding - Frame: %d, Line: %d", currentFrame, currentLine);
        explosionTimer += GetFrameTime();
        if(explosionTimer >= 0.05f){
            explosionTimer = 0;
            currentFrame++;

            if (currentFrame >= NUM_FRAME_PER_LINE) {
                active = false;
                isExploding = false;
                return;
                
                
            }

            frameRec.x = currentFrame * frameWidth;
            frameRec.y = 0;
        }
    }
}

void Player::Draw(){
    if(isExploding){
        //TraceLog(LOG_INFO, "Drawing explosion");
        float explosionScale = 4.0f;
        Rectangle source = frameRec;
        Rectangle dest = {
            explosionPos.x - (frameWidth * explosionScale) / 2, // center it
            explosionPos.y - (frameHeight * explosionScale) / 2,
            frameWidth * explosionScale, 
            frameHeight * explosionScale
        };
        DrawTexturePro(explosion, source, dest, {0, 0}, 0, WHITE);
    } else if (active) {
        Rectangle source = {0,0, (float)image.width, (float)image.height}; //set source image
        Rectangle dest = {position.x, position.y, image.width * scale, image.height * scale}; //scale
        Vector2 origin = {(image.width * scale) / 2, (image.height * scale)/2}; //rotate around center

        DrawTexturePro(image, source, dest, origin, rotation, WHITE);
    }
    

    
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

bool Player::Shoot(){
   return IsKeyPressed(KEY_SPACE);
}

void Player::StartExplosion(){
    isExploding = true;
    explosionPos = position;
    currentFrame = 0;
    currentLine = 0;
}

Vector2 Player::GetPlayerPosition(){
    return position;
}

float Player::GetPlayerRotation(){
    return rotation;    
}

Vector2 Player::GetPlayerSpeed(){
    return speed;
}

Rectangle Player::GetRect(){
    return Rectangle{position.x, position.y, (float)image.width, (float)image.height};
}

void Player::SetActive(bool value){
    active = value;
}

bool Player::IsActive(){
    return active;
}

bool Player::IsExploding(){
    return isExploding;
}