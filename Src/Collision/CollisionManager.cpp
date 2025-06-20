#include "CollisionManager.h"
#include <cstdio>

// �V���O���g���C���X�^���X�擾
CollisionManager& CollisionManager::Instance()
{
    static CollisionManager instance;
    return instance;
}

// Collider�ǉ�
void CollisionManager::AddCollider(std::shared_ptr<Collider> collider)
{
    colliders_.push_back(collider);
}

// �S�폜
void CollisionManager::Clear()
{
    colliders_.clear();
}

// ���t���[���Ăяo���F�Փ˃`�F�b�N�������߂�
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