#include "Title.h"
#include <Novice.h>
#include "SceneManager.h"

void Title::Update(char* keys, char* preKeys, int& scene) {
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        scene = kGame;
    }
}
void Title::Draw() {
    Novice::ScreenPrintf(550, 360, "TITLE SCENE: PRESS ENTER");
}