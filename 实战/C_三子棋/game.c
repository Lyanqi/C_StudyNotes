#include "game.h"
//函数定义
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
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);
		//判断x,y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1]==' ')
			{
				board[x - 1][y - 1] = '$';
				break;
			}
			else
			{
				printf("坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			
		}
	}
}

void ComputerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
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
//return '$':玩家赢
//return '#':电脑赢
//return 'Q':平局
//return 'C':继续
char IsWin(char board[Row][Col], int row, int col)
{
	//判断行是否有三个棋子相同
	for (int i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1]&& board[i][1] ==board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
		}
	}
	//判断列是否有三个棋子相同
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j]&& board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//判断两个对角线是否有三个棋子相同
	if (board[0][0]==board[1][1]&& board[1][1] ==board[2][2]&&board[0][0]!=' ')
	{
		return board[0][0];
	}
	if (board[2][0] == board[1][1]&& board[1][1] == board[0][2] && board[2][0] != ' ')
	{
		return board[2][0];
	}
	//判断是否平局
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
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了
}