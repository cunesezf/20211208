#include<stdio.h>
#include"game.h"
//初始化棋盘
void initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0;j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------扫雷游戏---------\n");
	//打印行号列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);
		for (j = 1; j < col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------扫雷游戏---------\n");
}


//布置雷区
void setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = 10;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';//这里表示雷布置进去了
			count--;
		}
	}

}




//排查雷区
//一.get_mine_count()函数用于统计所排雷周围有几个雷；
//二.FindMine()作用：
//1. 输入排查的坐标
//2. 检查坐标处是不是雷
//(1) 是雷 - 很遗憾炸死了 - 游戏结束
//(2) 不是雷 - 统计坐标周围有几个雷 - 存储排查雷的信息到show数组，游戏继续

static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count1 =0;
	for(i=-1;i<=1;i++)
		for (j = -1; j <= 1; j++)
		{
			mine[x + i][x + j];
			if (mine[x + i][x + j] = '1')
			{
				count1+=1;
			}
		}
	return count1;
}


void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{


	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col - 10)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);//x--(1,9)  y--(1,9)

		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				displayboard(mine, row, col);
				break;
			}
			else
			{
				//不是雷情况下，统计x,y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				//显示排查出的信息
				displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}

	if (win == row * col - 10)
	{
		printf("恭喜你，排雷成功\n");
		displayboard(mine, row, col);
	}
}