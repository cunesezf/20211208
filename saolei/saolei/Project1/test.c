#include"game.h"
void menu()
{
	printf("*********************\n");
	printf("****   1.play  ******\n");
	printf("****   0.exit  ******\n");
	printf("*********************\n");
}
//游戏程序的实现
void game()
{
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS,'*');//初始化棋盘
	displayboard(show, ROW, COL);//打印棋盘
	setmine(mine, ROW, COL);//布置雷
	displayboard(mine, ROW, COL);
	findmine(mine,show, ROW, COL);//排查雷
}

//游戏菜单设置
//主函数
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//进行游戏
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("选择错误，重新选择\n");
			break;

		}
	} while (input);
	return 0;
}