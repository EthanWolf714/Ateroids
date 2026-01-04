#ifndef GAME_H
#define GAME_H
#include "player.h"
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
    

private:
    Player player;
    std::vector<Bullet> bullets;
    Texture2D bulletTexture;
    std::vector<Asteroid> asteroids;
    Texture2D asteroidTexture;
    bool GameOver;
    int score;
    Sound hit;
    
};

#endif
