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
    //円の初期位置
    int circleX = 0;
    int circleY = 0;

    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //画面に円を描画させる
        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
        //円のX座標に動きをつける
        circleX += 2;
        circleY += 1;
        if (circleX >= 800)
        {
            circleX = 0;
            circleY = 0;
        }
        //裏画面の内容を表画面に反映させる
        ScreenFlip();

    }

    //画面に円を描画させる
    DrawCircle(320, 240, 30, GetColor(0, 0, 255), TRUE);

    //画面に点を描画させてね（Ｘ座標、Ｙ座標、点の色指定（赤, 緑, 青））
    DrawPixel(320, 240, GetColor(255, 0, 0));

    //キー入力待ち
    WaitKey();

    //Dxlib使用の終了処理
    DxLib_End();

    //ソースの終了
    return 0;
}