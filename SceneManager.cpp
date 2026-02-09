#include "SceneManager.h"
#include "Title.h"
#include "GameScene.h"
#include "Clear.h"
#include "Over.h"


Title* title = new Title();
GameScene* game = new GameScene();
Clear* clear = new Clear();
Over* over = new Over();

SceneManager::SceneManager() : currentScene_(kTitle) {}

void SceneManager::Update(char* keys, char* preKeys) {
  

    switch (currentScene_) {
    case kTitle:
        title->Update(keys, preKeys, currentScene_);
        // タイトルからゲームへ移動した瞬間に初期化
        if (currentScene_ == kGame) {
            game->Init();
        }
        break;

    case kGame:
        game->Update(keys, preKeys, currentScene_);
        break;

    case kClear:
        clear->Update(keys, preKeys, currentScene_);
       
        break;

    case kOver:
        over->Update(keys, preKeys, currentScene_);
        break;
    }
}

void SceneManager::Draw() {
    switch (currentScene_) {
    case kTitle: title->Draw(); break;
    case kGame:  game->Draw();  break;
    case kClear: clear->Draw(); break;
    case kOver:  over->Draw();  break;
    }
}