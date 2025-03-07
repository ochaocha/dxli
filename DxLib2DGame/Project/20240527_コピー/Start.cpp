#include "DxLib.h"
#include <math.h>
#include <stdio.h>

//定数
#define SCREEN_X 800
#define SCREEN_Y 600
#define STRAT_STRING_X 230
#define STRAT_STRING_Y 520

//フレームカウント
double frameCount = 0;
//デルタ時間
int prevCount, nowCout;
//画像ハンドル変数
int startScreenImage;
int alpha;
//メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---------------------------//
    // 基本設定
    //---------------------------//
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetMainWindowText("タイミングゲーム");
    SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);//画面の大きさ

    //DxLibの初期化処理
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }
    startScreenImage = LoadGraph("img/tittle01.png");
    int stringColor = GetColor(255, 99,71 );
    //---------------------------//
    // ゲームループ
    //---------------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        nowCout = GetNowCount();

        double deltaTime = (nowCout - prevCount) / 1000.0;
        //フレームカウントに追加
        frameCount += deltaTime * 1000;

        //画像の描画
        DrawExtendGraph(0, 0, SCREEN_X, SCREEN_Y, startScreenImage, TRUE);
        //アルファ地を計算
        alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.003))));

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            SetFontSize(30);
            DrawFormatString(STRAT_STRING_X, STRAT_STRING_Y, stringColor, "エンターでスタート");

            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            prevCount = nowCout;
    }


    //Dxlib終了処理
    DxLib_End();

    return 0;

}