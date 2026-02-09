#include "GameScene.h"
#include "Collision.h"
#include "SceneManager.h"
#include <Novice.h>

GameScene::GameScene() {
    player_ = new Player();
    Init();
}
GameScene::~GameScene() { delete player_; }

void GameScene::Init() {
    killCount_ = 0; playerLife_ = 3; missedCount_ = 0;
    for (int i = 0; i < kEnemyCount; i++) {
        enemies_[i].Init(1280.0f + (i * 200), 100.0f + (i * 60), -5.0f);
    }

    player_->Init();

}

void GameScene::Update(char* keys, char* preKeys, int& scene) {
    player_->Update(keys, preKeys);

    for (int i = 0; i < kEnemyCount; i++) {
        enemies_[i].Update();

        // 逃亡判定
        if (enemies_[i].GetIsOut()) {
            missedCount_++;
        }

        // 自機と敵の当たり判定
        if (enemies_[i].GetIsAlive()) {
            if (IsHit(player_->GetX(), player_->GetY(), player_->GetRadius(),
                enemies_[i].GetX(), enemies_[i].GetY(), enemies_[i].GetRadius())) {

                playerLife_--;
                // 当たった瞬間に死んだことにする。
                enemies_[i].SetIsAlive(false);
            }
        }

        // 弾と敵の当たり判定
        Bullet* b = player_->GetBullet();
        if (b->GetIsActive() && enemies_[i].GetIsAlive()) {
            if (IsHit(b->GetX(), b->GetY(), b->GetRadius(),
                enemies_[i].GetX(), enemies_[i].GetY(), enemies_[i].GetRadius())) {

                enemies_[i].SetIsAlive(false);
                b->SetIsActive(false);
                killCount_++;
            }
        }
    }

    // シーン遷移条件
    if (killCount_ >= 10) {
        scene = kClear;
    }
    if (playerLife_ <= 0 || missedCount_ >= 5) {
        scene = kOver;
    }
}

void GameScene::Draw() {
    player_->Draw();
    for (int i = 0; i < kEnemyCount; i++) enemies_[i].Draw();
    Novice::ScreenPrintf(20, 20, "KILLS:%d/10 LIFE:%d MISS:%d/5", killCount_, playerLife_, missedCount_);
}