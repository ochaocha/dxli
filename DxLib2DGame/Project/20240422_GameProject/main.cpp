#include "DxLib.h"//Dxライブラリーをインクルード(読み込み)

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{
    //基本設計
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
    SetGraphMode(800, 600, 32);//画面の大きさ

    //DxLibの初期化処理
    if (DxLib_Init() == -1)
    {
     //エラーが起きたら直ちに終了
        return -1;
    }
    int stringX1 = 10;
    int stringY1 = 50;
    //円の初期位置
    int circleX = 150;
    int circleY = 200;
    int stringX = 10;
    int stringY = 15;
    int circleColor = GetColor(0, 0, 255);
    int stringColor = GetColor(255, 255, 255);
    int stringColor2 = GetColor(255, 0, 0);
    int mouseX = 0;
    int mouseY = 0;
    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //文字の大きさの指
        SetFontSize(32);
        // 画面に文字表示
        //DrawString(10, 15, "HelloWould", StringColor,"X:%d Y:%d",circleX,circleY);
        DrawFormatString(stringX, stringY, stringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
        //画面に円を描画させる
        DrawCircle(circleX, circleY, 30, circleColor, TRUE);
        //マウスの座標を取得
        GetMousePoint(&mouseX, &mouseY);
        //マウスがクリックされたら
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit!", stringColor2);
        }

        if (CheckHitKey(KEY_INPUT_UP))
        {
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
        }

        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }

        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            if (circleX <= 40)
            {
                circleX += 3;
            }
            else
            {
                circleX -= 3;
            }

        }

        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            if (circleX >= 740)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }

        }
  
  

            //円のX座標に動きをつける
            /*circleX += 40;
            circleY += 30;
            if (circleX >= 800)
            {
                circleX = 0;
                circleY = 0;
            }*/

            //裏画面の内容を表画面に反映させる
            ScreenFlip();

    }


    //画面に円を描画させる
    DrawCircle(320, 240, 30, GetColor(0, 0, 255), TRUE);

    

    //キー入力待ち
    WaitKey();

    //Dxlib使用の終了処理
    DxLib_End();

    //ソースの終了
    return 0;
}