#include "DxLib.h"
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void displayStatus(int strikes, int balls, int outs, int hits) {
    char buffer[256];
    sprintf(buffer, "ストライク: %d  ボール: %d  アウト: %d  ヒット: %d", strikes, balls, outs, hits);
    DrawString(10, 50, buffer, GetColor(255, 255, 255));
}
int main() {
    // DXライブラリの初期化
    if (DxLib_Init() == -1) {
        return -1; // エラーが発生した場合は終了
    }
    srand(time(0)); // 乱数のシードを設定
    int strikes = 0;
    int balls = 0;
    int outs = 0;
    int hits = 0;
    int pitcherChoice = -1;
    do {
        // 画面クリア
        ClearDrawScreen();
        // 画面にメッセージを表示
        DrawString(10, 10, "投球を選んでください (0: ストレート, 1: カーブ, 2: スライダー, 3: シンカー):", GetColor(255, 255, 255));
        displayStatus(strikes, balls, outs, hits);
        // キー入力を受け付ける
        if (CheckHitKey(KEY_INPUT_0)) pitcherChoice = 0;
        if (CheckHitKey(KEY_INPUT_1)) pitcherChoice = 1;
        if (CheckHitKey(KEY_INPUT_2)) pitcherChoice = 2;
        if (CheckHitKey(KEY_INPUT_3)) pitcherChoice = 3;
        if (pitcherChoice != -1) {
            int batterChoice = rand() % 4;
            char result[256];
            sprintf(result, "バッターの選択: %d", batterChoice);
            DrawString(10, 70, result, GetColor(255, 255, 255));
            if (pitcherChoice == batterChoice) {
                int hitOutcome = rand() % 100;
                if (hitOutcome < 75) {
                    hits++;
                    DrawString(10, 90, "ヒット！", GetColor(255, 0, 0));
                    strikes = 0;
                    balls = 0;
                }
                else {
                    outs++;
                    DrawString(10, 90, "アウト！", GetColor(0, 255, 0));
                    strikes = 0;
                    balls = 0;
                }
            }
            else {
                int strikeOutcome = rand() % 100;
                if (strikeOutcome < 75) {
                    strikes++;
                    DrawString(10, 90, "ストライク！", GetColor(0, 255, 255));
                    if (strikes == 3) {
                        outs++;
                        DrawString(10, 110, "三振！アウト！", GetColor(0, 255, 0));
                        strikes = 0;
                        balls = 0;
                    }
                }
                else {
                    balls++;
                    DrawString(10, 90, "ボール！", GetColor(255, 255, 0));
                    if (balls == 4) {
                        hits++;
                        DrawString(10, 110, "フォアボール！ヒット！", GetColor(255, 0, 0));
                        strikes = 0;
                        balls = 0;
                    }
                }
            }
            // 投球選択リセット
            pitcherChoice = -1;
        }
        // 画面を更新
        ScreenFlip();
        // エスケープキーで終了
        if (CheckHitKey(KEY_INPUT_ESCAPE)) {
            break;
        }
    } while (outs < 3 && hits < 4);
    ClearDrawScreen();
    if (outs == 3) {
        DrawString(10, 10, "勝利！相手チームを抑えました！", GetColor(255, 255, 255));
    }
    else {
        DrawString(10, 10, "敗北！ヒットが4回出ました。", GetColor(255, 255, 255));
    }
    ScreenFlip();
    WaitKey();
    // DXライブラリの終了処理
    DxLib_End();
    return 0;
}