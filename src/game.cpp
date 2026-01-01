#include "game.h"

Game::Game(){

}

Game::~Game(){

}

void Game::Draw(){
    player.Draw();
    asteroid.Draw();
}

void Game::HandleInput(){
    player.Move();
    player.Rotate();
}

void Game::Update(){
    HandleInput();
}