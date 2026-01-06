#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "powerup.h"
#include "asteroid.h"
#include "bullet.h"
#include <vector>
#include "math.h"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    int HandleScore();
    void Restart();
    Vector2 GetRandomEdgePosition();
    Vector2 GetRandomVelocity();
    bool IsGameOver();
    bool PlayerDead();
    int HandleLives();
    bool IsLevelComplete();
    void StartNextLevel();

private:
    Player player;
    std::vector<PowerUp> powerups;
    std::vector<Bullet> bullets;
    Texture2D bulletTexture;
    std::vector<Asteroid> asteroids;
    Texture2D asteroidTexture;
    Texture2D extraLifeTexture;
    Texture2D sheildTexture;
    bool GameOver;
    int score;
    Sound hit;
    Sound damage;
    Sound pickup;
    int level;
};

#endif
