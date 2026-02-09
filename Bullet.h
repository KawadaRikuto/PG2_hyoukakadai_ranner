#pragma once
class Bullet {
private:
    float x_, y_, speed_, radius_;
    bool isActive_;
public:
    Bullet();
    void Update();
    void Draw();
    void Activate(float x, float y);
    bool GetIsActive() const { return isActive_; }
    void SetIsActive(bool active) { isActive_ = active; }
    float GetX() const { return x_; }
    float GetY() const { return y_; }
    float GetRadius() const { return radius_; }
};
