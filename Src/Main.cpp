#include "DxLib.h"

#include <iostream>
#include "Collision/BoxCollider.h"
#include "Collision/CollisionManager.h"

//�萔(�S�đ啶���ŏ���)
//--------------------------------------
//�Q�[���̃E�B���h�E�T�C�Y
const int SCREEN_SIZE_X = 640;	//�Q�[���E�B���h�E�̉��T�C�Y
const int SCREEN_SIZE_Y = 480;	//�Q�[���E�B���h�E�̏c�T�C�Y

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�V�X�e������
    //----------------------------------
    SetWindowText("�w�Дԍ�_���O");						//�Q�[���E�B���h�E�̃^�C�g��
    SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);		//�Q�[���E�B���h�E�̃T�C�Y�ƐF���[�h��ݒ�
    ChangeWindowMode(true);								//�Q�[���E�B���h�E�̕\�����@�ifalse�F�t���X�N���[���j
    if (DxLib_Init() == -1)								//DX���C�u�����̏���������
    {
        //DX���C�u�����̏��������s�̈׃V�X�e���I��
        return -1;
    }

    //�`�悷���ʂ𗠂̉�ʂɐݒ�
    SetDrawScreen(DX_SCREEN_BACK);

    auto box1 = std::make_shared<BoxCollider>(Vector2{ 0, 0 }, Vector2{ 50, 50 });
    auto box2 = std::make_shared<BoxCollider>(Vector2{ 50, 50 }, Vector2{ 50, 50 });
    auto box3 = std::make_shared<BoxCollider>(Vector2{ 75, 50 }, Vector2{ 50, 50 });
    auto box4 = std::make_shared<BoxCollider>(Vector2{ 100, 100 }, Vector2{ 50, 50 });
    auto box5 = std::make_shared<BoxCollider>(Vector2{ 100, 100 }, Vector2{ 50, 50 });
    auto box6 = std::make_shared<BoxCollider>(Vector2{ 200, 200 }, Vector2{ 50, 50 });

    auto& manager = CollisionManager::Instance();
    manager.AddCollider(box1);
    manager.AddCollider(box2);
    manager.AddCollider(box3);
    manager.AddCollider(box4);
    manager.AddCollider(box5);
    manager.AddCollider(box6);

    //�Q�[�����[�v
    //----------------------------------
    while (ProcessMessage() == 0)
    {
        if (CheckHitKey(KEY_INPUT_W)) box1->SetPosition({ box1->GetPosition().x,box1->GetPosition().y - 5 });
        if (CheckHitKey(KEY_INPUT_S)) box1->SetPosition({ box1->GetPosition().x,box1->GetPosition().y + 5 });
        if (CheckHitKey(KEY_INPUT_A)) box1->SetPosition({ box1->GetPosition().x - 5 ,box1->GetPosition().y});
        if (CheckHitKey(KEY_INPUT_D)) box1->SetPosition({ box1->GetPosition().x + 5 ,box1->GetPosition().y});

        manager.Update();

        //�`�揈��
        //----------------------------------
        ClearDrawScreen();					//�`�悷���ʂ̓��e������

        DrawBox(
            box1->GetPosition().x,
            box1->GetPosition().y,
            box1->GetPosition().x + box1->GetSize().x,
            box1->GetPosition().y + box1->GetSize().y,
            0xFFFFFF,
            true
        );

        DrawBox(
            box2->GetPosition().x,
            box2->GetPosition().y,
            box2->GetPosition().x + box2->GetSize().x,
            box2->GetPosition().y + box2->GetSize().y,
            0xFF0000,
            true
        );

        DrawBox(
            box3->GetPosition().x,
            box3->GetPosition().y,
            box3->GetPosition().x + box3->GetSize().x,
            box3->GetPosition().y + box3->GetSize().y,
            0xFF0000,
            true
        );
        DrawBox(
            box4->GetPosition().x,
            box4->GetPosition().y,
            box4->GetPosition().x + box4->GetSize().x,
            box4->GetPosition().y + box4->GetSize().y,
            0xFF0000,
            true
        );
        DrawBox(
            box5->GetPosition().x,
            box5->GetPosition().y,
            box5->GetPosition().x + box5->GetSize().x,
            box5->GetPosition().y + box5->GetSize().y,
            0xFF0000,
            true
        );
        DrawBox(
            box6->GetPosition().x,
            box6->GetPosition().y,
            box6->GetPosition().x + box6->GetSize().x,
            box6->GetPosition().y + box6->GetSize().y,
            0xFF0000,
            true
        );

        //���̉�ʂ�\�̉�ʂɏu�ԃR�s�[
        ScreenFlip();
    }

    //�V�X�e���I������
    //----------------------------------
    DxLib_End();		//DX���C�u�����̏I������
    return 0;
}