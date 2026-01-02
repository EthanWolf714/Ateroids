#include "game.h"

Game::Game(){

}

Game::~Game(){

}

void Game::Draw(){
    player.Draw();
    asteroid.Draw();
    Texture2D bulletSprite = LoadTexture("build/SPRITES/BULLET.png");
    std::vector<Bullet> bullets;
}

void Game::HandleInput(){
    player.Move();
    player.Rotate();
}

void Game::Update(){
    HandleInput();
}