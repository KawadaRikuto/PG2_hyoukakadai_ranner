#include "Clear.h"
#include <Novice.h>
#include "SceneManager.h"

void Clear::Update(char* keys, char* preKeys, int& scene) {
    // エンターキーでタイトルへ戻る
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        scene = kTitle;
    }
}

void Clear::Draw() {
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid); // 背景を青に
    Novice::ScreenPrintf(550, 300, "== GAME CLEAR ==");
    Novice::ScreenPrintf(520, 360, "PRESS ENTER TO TITLE");
}