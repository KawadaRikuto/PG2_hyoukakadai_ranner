#pragma once

enum SceneType { kTitle, kGame, kClear, kOver };

class SceneManager {
private:
    int currentScene_;
public:
    SceneManager();
    void Update(char* keys, char* preKeys);
    void Draw();
};