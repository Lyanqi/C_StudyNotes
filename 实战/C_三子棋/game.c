#include "game.h"
//��������
void InitBoard(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j<col-1)
			{
				printf("|");
			}
			
			
		}
		printf("\n");
		if (i<row-1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j<col-1)
				{
					printf("|");
				}
				

			}
			printf("\n");
		}
		
	}
}

void PlayerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);
		//�ж�x,y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1]==' ')
			{
				board[x - 1][y - 1] = '$';
				break;
			}
			else
			{
				printf("���걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
			
		}
	}
}

void ComputerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		
	}
}
//return '$':���Ӯ
//return '#':����Ӯ
//return 'Q':ƽ��
//return 'C':����
char IsWin(char board[Row][Col], int row, int col)
{
	//�ж����Ƿ�������������ͬ
	for (int i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1]&& board[i][1] ==board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
		}
	}
	//�ж����Ƿ�������������ͬ
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j]&& board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//�ж������Խ����Ƿ�������������ͬ
	if (board[0][0]==board[1][1]&& board[1][1] ==board[2][2]&&board[0][0]!=' ')
	{
		return board[0][0];
	}
	if (board[2][0] == board[1][1]&& board[1][1] == board[0][2] && board[2][0] != ' ')
	{
		return board[2][0];
	}
	//�ж��Ƿ�ƽ��
	if (IsFull(board,Row,Col)==1)
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
	
}

int IsFull(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j]==' ')
			{
				return 0;//����û��
			}
		}
	}
	return 1;//��������
}