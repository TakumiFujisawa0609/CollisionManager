#pragma once

#include <vector>
#include <memory>
#include "Collider.h"
#include "BoxCollider.h"

class CollisionManager
{
public:
    static CollisionManager& Instance();

    void AddCollider(std::shared_ptr<Collider> collider);
    void Clear();
    void Update();

private:
    CollisionManager() = default;
    ~CollisionManager() = default;

    std::vector<std::shared_ptr<Collider>> colliders_;
};