#include "game.h"

Game::Game(){
    bulletTexture = LoadTexture("build/SPRITES/BULLET.png");
}

Game::~Game(){
    UnloadTexture(bulletTexture);
}

void Game::Draw(){
    player.Draw();
    asteroid.Draw();
    
    std::vector<Bullet> bullets;
}

void Game::HandleInput(){
    player.Move();
    player.Rotate();
}

void Game::Update(){
    HandleInput();
}