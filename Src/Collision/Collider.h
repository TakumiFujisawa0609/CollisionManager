#pragma once

struct Vector2
{
    float x;
    float y;
};

class Collider
{
public:
    virtual ~Collider() = default;

    virtual bool CheckCollision(const Collider& other) const = 0;

    virtual Vector2 GetPosition() const = 0;
};