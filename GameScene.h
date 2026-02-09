#pragma once
#include "Player.h"
#include "Enemy.h"

class GameScene {
private:
    Player* player_;
    static const int kEnemyCount = 10;
    Enemy enemies_[kEnemyCount];

    int killCount_;
    int playerLife_;
    int missedCount_;

public:
    GameScene();
    ~GameScene();
    void Init();
    void Update(char* keys, char* preKeys, int& scene);
    void Draw();
};