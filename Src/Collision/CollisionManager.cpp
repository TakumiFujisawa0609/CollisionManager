#include "CollisionManager.h"
#include <cstdio>

// シングルトンインスタンス取得
CollisionManager& CollisionManager::Instance()
{
    static CollisionManager instance;
    return instance;
}

// Collider追加
void CollisionManager::AddCollider(std::shared_ptr<Collider> collider)
{
    colliders_.push_back(collider);
}

// 全削除
void CollisionManager::Clear()
{
    colliders_.clear();
}

// 毎フレーム呼び出し：衝突チェック＆押し戻し
void CollisionManager::Update()
{
    for (size_t i = 0; i < colliders_.size(); ++i)
    {
        for (size_t j = i + 1; j < colliders_.size(); ++j)
        {
            if (colliders_[i]->CheckCollision(*colliders_[j]))
            {
                printf("Collision detected between #%zu and #%zu\n", i, j);

                BoxCollider* boxA = dynamic_cast<BoxCollider*>(colliders_[i].get());
                BoxCollider* boxB = dynamic_cast<BoxCollider*>(colliders_[j].get());

                if (boxA && boxB)
                {
                    boxA->ResolveCollision(*boxB);
                }
            }
        }
    }
}