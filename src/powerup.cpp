#include "powerup.h"
#include "raylib.h"

PowerUp::PowerUp( Vector2 startPos , Texture2D* texture, std::string type) {
    status = true;
    image = texture;
    scale = 1.0f;
    position = startPos;
    this ->type = type;
}
PowerUp::~PowerUp(){
    
}

void PowerUp::Update(){

}

void PowerUp::Draw(){
    DrawTextureEx(*image, position, 0, scale, WHITE);
}

Rectangle PowerUp::GetRect(){
    return Rectangle{position.x, position.y, (float)image->width, (float)image->height};
}

std::string PowerUp::GetType(){
    return type;
}

void PowerUp::SetActive(bool active){
    status = active;
}

bool PowerUp::IsActive(){
    return status;
}