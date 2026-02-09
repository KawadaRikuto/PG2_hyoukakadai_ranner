#include "Player.h"
#include <Novice.h>

Player::Player() : x_(100), y_(360), speed_(5.0f), radius_(20.0f) {}


void Player::Init() {
    x_ = 100.0f;
    y_ = 360.0f;
    bullet_.SetIsActive(false);
}

void Player::Update(char* keys, char* preKeys) {
    if (keys[DIK_W]) {
        y_ -= speed_;
    }

    if (keys[DIK_S]) {
        y_ += speed_;
    }

    if (keys[DIK_A]) {
        x_ -= speed_;
    }

    if (keys[DIK_D]) {
        x_ += speed_;
    }

    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_.GetIsActive()) {
        bullet_.Activate(x_, y_);
    }

    bullet_.Update();
}

void Player::Draw() {
    bullet_.Draw();
    Novice::DrawEllipse((int)x_, (int)y_, (int)radius_, (int)radius_, 0.0f, GREEN, kFillModeSolid);
}