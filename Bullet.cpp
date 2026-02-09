#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() : x_(0), y_(0), speed_(10.0f), radius_(8.0f), isActive_(false) {}

void Bullet::Activate(float x, float y) { x_ = x; y_ = y; isActive_ = true; }

void Bullet::Update() {
    if (isActive_) {
        x_ += speed_;
        if (y_ < -radius_) isActive_ = false;
    }
}

void Bullet::Draw() {
    if (isActive_) Novice::DrawEllipse((int)x_, (int)y_, (int)radius_, (int)radius_, 0.0f, WHITE, kFillModeSolid);
}