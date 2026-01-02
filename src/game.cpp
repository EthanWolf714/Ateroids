#include "game.h"
#include <algorithm>

Game::Game()
{
    bulletTexture = LoadTexture("build/SPRITES/BULLET.png");
}

Game::~Game()
{
    UnloadTexture(bulletTexture);
}

void Game::Draw()
{
    player.Draw();
    asteroid.Draw();

    for (auto &bullet : bullets)
    {
        bullet.Draw();
    }
}

void Game::HandleInput()
{
    player.Move();
    player.Rotate();

    if (player.Shoot())
    {
        // calculate bullet direction from player rotation
        float angle = player.GetPlayerRotation() * DEG2RAD - (PI/2);
        float bulletSpeed = 500.f;
        //offset for bullet spawnign in front of the ship
        float spawnOffset = 15.f;

        Vector2 spawnPos = {
            player.GetPlayerPosition().x + cos(angle) * spawnOffset,
            player.GetPlayerPosition().y + sin(angle) * spawnOffset,

        };

        // calculate bullet speed.
        Vector2 bulletVelocity = {
            cos(angle) * bulletSpeed + player.GetPlayerSpeed().x,
            sin(angle) * bulletSpeed + player.GetPlayerSpeed().y
        } ;

        // create and add bullets to the bullets array
        bullets.push_back(Bullet(
            spawnPos,
            bulletVelocity,
            &bulletTexture));
    }
}

void Game::Update()
{
    HandleInput();

    // update all bullets
    for (auto &bullet : bullets)
    {
        bullet.Update();
    }

    // remove dead bullets marked as inactive
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
                       [](Bullet &b)
                       { return !b.IsActive(); }),
        bullets.end());
}