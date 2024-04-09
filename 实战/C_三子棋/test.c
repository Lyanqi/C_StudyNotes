#define _CRT_SECURE_NO_WARNINGS

#define Max(X,Y) (X>Y?X:Y)
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "game.h"

void Menu()
{
	printf("************************\n");
	printf("**** 1.play 0.exit *****\n");
	printf("************************\n");
}

void game()
{
	char ret = 0;

	char board[Row][Col] = { 0 };
	//初始化棋盘
	InitBoard(board,Row,Col);
	//打印棋盘
	DisplayBoard(board, Row, Col);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, Row, Col);
		DisplayBoard(board, Row, Col);
		//判断玩家是否赢
		ret = IsWin(board, Row, Col);
		if (ret!='C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, Row, Col);
		DisplayBoard(board, Row, Col);
		//判断电脑是否赢
		ret = IsWin(board, Row, Col);
		if (ret!='C')
		{
			break;
		}
	}
	if (ret=='$')
	{
		printf("玩家赢了\n");
	}
	else if (ret=='#')
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}

int main()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("请输入:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);


	return 0;
}



