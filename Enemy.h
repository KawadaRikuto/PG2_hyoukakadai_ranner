#pragma once
class Enemy {
private:
    float x_, y_, speedX_, radius_;
    bool isAlive_;
    bool isOut_;
public:
    Enemy();
    void Init(float x, float y, float speed);
    void Update();
    void Draw();

    float GetX() const { return x_; }
    float GetY() const { return y_; }
    float GetRadius() const { return radius_; }
    void SetIsAlive(bool alive) { isAlive_ = alive; }
    bool GetIsOut() const { return isOut_; }
    void SetIsOut(bool out) { isOut_ = out; }
    bool GetIsAlive() const { return isAlive_; }
};