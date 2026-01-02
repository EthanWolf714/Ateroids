#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();

private:
    Player player;
    Asteroid asteroid;
    std::vector<Bullet> bullets;
};

#endif
