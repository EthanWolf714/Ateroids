#include "player.h"



Player::Player()
{

    image = LoadTexture("build/SPRITES/PLAYER.png");
    position.x = (GetScreenWidth() - image.width)/ 2;
    position.y = (GetScreenHeight() - image.height) / 2;
    scale = 2.0;
    rotation = 0.0f;
    active = true;
    lives = 3;
    hasSheild = false;
    bulletSound = LoadSound("build/SFX/BULLET_1.wav");
    explosionSound = LoadSound("build/SFX/GAME_OVER_1.wav");
    explosion = LoadTexture("build/SPRITES/EXPLOSION.png");
    isExploding = false;
    explosionTimer = 0.0f;
    explosionFrame = 0;
    explosionPos = {0, 0};



    

    

}

Player::~Player(){
    UnloadTexture(image);
    UnloadSound(bulletSound);
    UnloadSound(explosionSound);

}

void Player::Update() {
    if (isExploding) {
        explosionTimer += GetFrameTime();
        //calculate explosion animation speed
        if (explosionTimer >= 0.07f) {  
            explosionTimer = 0;
            explosionFrame++;
            
            if (explosionFrame >= 5) {  // all 5 frames done
                isExploding = false;
                
                if(lives > 0){
                    Reset();
                }else{
                    active = false;
                }
            }
        }
    }

    float spriteWidth = image.width * scale;
    float spriteHeight = image.height * scale;

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

void Player::Reset(){
    position.x = (GetScreenWidth() - image.width)/ 2;
    position.y = (GetScreenHeight() - image.height) / 2;
    scale = 2.0;
    rotation = 0.0f;
    active = true;
    isExploding = false;
    explosionTimer = 0.0f;
    explosionFrame = 0;
    explosionPos = {0, 0};
}

void Player::Draw(){
    
    if (isExploding) {
        //get fram width and height and scale to player
        float frameWidth = 120.0f / 5.0f;  // 5 frames = 24 pixels each
        float frameHeight = 20.0f;
        float scale = 2.0f;
        
        //set rectangle for moving through sprite sheet
        Rectangle source = {explosionFrame * frameWidth, 0, frameWidth, frameHeight};
        Rectangle dest = {
            explosionPos.x - (frameWidth * scale) / 2,
            explosionPos.y - (frameHeight * scale) / 2,
            frameWidth * scale,
            frameHeight * scale
        };
        //draw animation
        DrawTexturePro(explosion, source, dest, {0, 0}, 0, WHITE);
    } else if (active) {
        //draw ship sprite
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
   if(IsKeyPressed(KEY_SPACE)) {
    PlaySound(bulletSound);
    return true;
   }
   return false;
}

//starts explosion animation
void Player::StartExplosion() {
    PlaySound(explosionSound);
    isExploding = true;
    explosionFrame = 0;
    explosionTimer = 0.07f;
    explosionPos = position;
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

void Player::AddLife(){
    lives++;
    TraceLog(LOG_INFO, "AddLife called! Lives now: %d", lives);

}

void Player::ActivateShield(){
    hasSheild = true;
}

void Player::DeactivateShield(){
    hasSheild = false;
}

bool Player::HasSheild(){
    return hasSheild;
}

int Player::GetLives(){
    return lives;
}

void Player::RemoveLife(){
     TraceLog(LOG_INFO, "RemoveLife called! Lives now: %d", lives);
    lives--;
}

