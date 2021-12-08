//测试模块
#include<stdio.h>
#include"game.h"
void game()
{
	//存储数据-二维数组创建
	char board[ROW][COL];
	initboard(board, ROW, COL);//初始化棋盘-初始化空格
	displayboard(board, ROW, COL);//打印一下棋盘，本质上是打印数组内容
	char ret = 0;//接受游戏状态
	while (1)
	{
		//玩家下棋
		 playermove(board, ROW, COL);
		 displayboard(board, ROW, COL);
		 //判断玩家是否赢得游戏
		 ret=iswin(board, ROW, COL);
		 if (ret!= 'C')
		 {
			 break;
		 }
		//电脑下棋
		 computermove(board, ROW, COL);
		 displayboard(board, ROW, COL);
		 ret = iswin(board, ROW, COL);
		 if (ret!='C')
		 {
			 break;
		 }
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	
}
void menu()
{
	printf("*********************\n");
	printf("***1.开始，0.结束****\n");
	printf("*********************\n");
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("结束游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}