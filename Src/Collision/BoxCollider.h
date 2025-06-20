#pragma once
#include "Collider.h"

class BoxCollider : public Collider
{
public:
    BoxCollider(Vector2 pos, Vector2 size)
        : pos_(pos), size_(size) {}

    Vector2 GetPosition() const override { return pos_; }
    Vector2 GetSize() const { return size_; }

    void SetPosition(Vector2 pos) { pos_ = pos; }

    bool CheckCollision(const Collider& other) const override;
    void ResolveCollision(BoxCollider& other);

private:
    Vector2 pos_;
    Vector2 size_;
};