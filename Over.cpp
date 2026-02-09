#include "Over.h"
#include <Novice.h>
#include "SceneManager.h"

void Over::Update(char* keys, char* preKeys, int& scene) {
    // エンターキーでタイトルへ戻る
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        scene = kTitle;
    }
}

void Over::Draw() {
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, RED, kFillModeSolid);
    Novice::ScreenPrintf(550, 300, "== GAME OVER ==");
    Novice::ScreenPrintf(520, 360, "PRESS ENTER TO TITLE");
}