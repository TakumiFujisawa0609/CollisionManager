#include "DxLib.h"

#include <iostream>
#include "Collision/BoxCollider.h"
#include "Collision/CollisionManager.h"

//定数(全て大文字で書く)
//--------------------------------------
//ゲームのウィンドウサイズ
const int SCREEN_SIZE_X = 640;	//ゲームウィンドウの横サイズ
const int SCREEN_SIZE_Y = 480;	//ゲームウィンドウの縦サイズ

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //システム処理
    //----------------------------------
    SetWindowText("学籍番号_名前");						//ゲームウィンドウのタイトル
    SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);		//ゲームウィンドウのサイズと色モードを設定
    ChangeWindowMode(true);								//ゲームウィンドウの表示方法（false：フルスクリーン）
    if (DxLib_Init() == -1)								//DXライブラリの初期化処理
    {
        //DXライブラリの初期化失敗の為システム終了
        return -1;
    }

    //描画する画面を裏の画面に設定
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

    //ゲームループ
    //----------------------------------
    while (ProcessMessage() == 0)
    {
        if (CheckHitKey(KEY_INPUT_W)) box1->SetPosition({ box1->GetPosition().x,box1->GetPosition().y - 5 });
        if (CheckHitKey(KEY_INPUT_S)) box1->SetPosition({ box1->GetPosition().x,box1->GetPosition().y + 5 });
        if (CheckHitKey(KEY_INPUT_A)) box1->SetPosition({ box1->GetPosition().x - 5 ,box1->GetPosition().y});
        if (CheckHitKey(KEY_INPUT_D)) box1->SetPosition({ box1->GetPosition().x + 5 ,box1->GetPosition().y});

        manager.Update();

        //描画処理
        //----------------------------------
        ClearDrawScreen();					//描画する画面の内容を消去

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

        //裏の画面を表の画面に瞬間コピー
        ScreenFlip();
    }

    //システム終了処理
    //----------------------------------
    DxLib_End();		//DXライブラリの終了処理
    return 0;
}