#pragma once
#include "Bullet.h"

class Player {
private:
    float x_, y_, speed_, radius_;
    Bullet bullet_;
public:
    Player();
    void Update(char* keys, char* preKeys);
    void Draw();
    void Init();
    // アクセッサ
    float GetX() const { return x_; }
    float GetY() const { return y_; }
    float GetRadius() const { return radius_; }
    Bullet* GetBullet() { return &bullet_; }
};