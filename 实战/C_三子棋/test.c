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
	//��ʼ������
	InitBoard(board,Row,Col);
	//��ӡ����
	DisplayBoard(board, Row, Col);
	//����
	while (1)
	{
		//�������
		PlayerMove(board, Row, Col);
		DisplayBoard(board, Row, Col);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, Row, Col);
		if (ret!='C')
		{
			break;
		}
		//��������
		ComputerMove(board, Row, Col);
		DisplayBoard(board, Row, Col);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, Row, Col);
		if (ret!='C')
		{
			break;
		}
	}
	if (ret=='$')
	{
		printf("���Ӯ��\n");
	}
	else if (ret=='#')
	{
		printf("����Ӯ��\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}

int main()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("������:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);


	return 0;
}



