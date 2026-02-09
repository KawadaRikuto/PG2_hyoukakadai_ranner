#include "Enemy.h"
#include <Novice.h>


Enemy::Enemy() : x_(1300), y_(150), speedX_(-5.0f), radius_(25.0f), isAlive_(true) {}

// Enemy.cpp
void Enemy::Update() {
    isOut_ = false;

    if (isAlive_) {
        x_ += speedX_;
        if (x_ < -radius_) {
            x_ = 1300.0f;
            isOut_ = true;
        }
    } else {
       
        x_ = 1300.0f;
        isAlive_ = true;
    }
}

void Enemy::Init(float x, float y, float speed) { x_ = x; y_ = y; speedX_ = speed; isAlive_ = true; }

void Enemy::Draw() {
    if (isAlive_) {
        Novice::DrawEllipse((int)x_, (int)y_, (int)radius_, (int)radius_, 0.0f, RED, kFillModeSolid);
    }
}