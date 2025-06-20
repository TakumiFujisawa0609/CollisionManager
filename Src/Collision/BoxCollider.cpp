#include "BoxCollider.h"
#include <algorithm>
#include <cmath>

bool BoxCollider::CheckCollision(const Collider& other) const
{
    const BoxCollider* box = dynamic_cast<const BoxCollider*>(&other);
    if (!box) return false;

    Vector2 aPos = pos_;
    Vector2 aSize = size_;
    Vector2 bPos = box->GetPosition();
    Vector2 bSize = box->GetSize();

    return (aPos.x < bPos.x + bSize.x &&
        aPos.x + aSize.x > bPos.x &&
        aPos.y < bPos.y + bSize.y &&
        aPos.y + aSize.y > bPos.y);
}

void BoxCollider::ResolveCollision(BoxCollider& other)
{
    Vector2 aPos = pos_;
    Vector2 aSize = size_;
    Vector2 bPos = other.GetPosition();
    Vector2 bSize = other.GetSize();

    float aMinX = aPos.x;
    float aMaxX = aPos.x + aSize.x;
    float aMinY = aPos.y;
    float aMaxY = aPos.y + aSize.y;

    float bMinX = bPos.x;
    float bMaxX = bPos.x + bSize.x;
    float bMinY = bPos.y;
    float bMaxY = bPos.y + bSize.y;

    // èdÇ»ÇËó 
    float overlapX = std::min(aMaxX, bMaxX) - std::max(aMinX, bMinX);
    float overlapY = std::min(aMaxY, bMaxY) - std::max(aMinY, bMinY);

    // ç≈è¨ÇÃé≤ï˚å¸Ç…âüÇµñﬂÇ∑
    if (overlapX < overlapY)
    {
        float half = overlapX * 0.5f;

        if (aPos.x < bPos.x)
        {
            pos_.x -= half;
            other.pos_.x += half;
        }
        else
        {
            pos_.x += half;
            other.pos_.x -= half;
        }
    }
    else
    {
        float half = overlapY * 0.5f;

        if (aPos.y < bPos.y)
        {
            pos_.y -= half;
            other.pos_.y += half;
        }
        else
        {
            pos_.y += half;
            other.pos_.y -= half;
        }
    }
}
