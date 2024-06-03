#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int main(void)
{
	//変数宣言
	int plyScore = 0, emyScore = 0;
	int ply, emy;
	int round = 0;
	int maxRound = 5;
	//乱数の初期化
	srand((unsigned int)time(NULL));
	//ゲーム開始
	while (round < maxRound || plyScore == emyScore)
	{
		//ラウンドカウントアップ
		round++;
		//プレイヤーターン
		printf("PlayerTurn\n");
		emy = rand() % 3;
		printf("%d", emy);
		while (true)
		{
			scanf("%d", &ply);
			if (0 > ply || 3 < ply)
			{
				printf("入力に誤りがあります。再度入力して下さい。\n");
			}
			else
			{
				break;
			}
		}
		//判定
		if (ply != emy)
		{
			printf("Goal\n");
			plyScore++;
		}
		else
		{
			printf("Stop!\n");
		}
		//CPUターン
		printf("EnemyTurn\n");
		emy = rand() % 3;
		printf("%d", emy);
		while (true)
		{
			scanf("%d", &ply);
			if (0 > ply || 3 < ply)
			{
				printf("入力に誤りがあります。再度入力して下さい。\n");
			}
			else
			{
				break;
			}
		}
		//判定
		if (ply != emy)
		{
			printf("Goal\n");
			emyScore++;
		}
		else
		{
			printf("Stop!\n");
		}

		printf("%dRound\n PLAYER:%d vs ENEMY:%d\n", round, plyScore, emyScore);
		//サドンデス突入選出
		if (round == maxRound && plyScore == emyScore)
		{
			printf("サドンデスに突入しました。\n");
		}

	}
	//勝負判定
	if (plyScore > emyScore)
	{
		printf("PLAYER WINNER!!\n");
	}
	else
	{
		printf("ENEMY WINNER!!\n");
	}
	return 0;
}