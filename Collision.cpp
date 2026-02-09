#include "Collision.h"

bool IsHit(float x1, float y1, float r1, float x2, float y2, float r2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return (dx * dx + dy * dy) <= (r1 + r2) * (r1 + r2);
}