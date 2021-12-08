#include<stdio.h>
#include"game.h"
//��ʼ������
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

//��ӡ����
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------ɨ����Ϸ---------\n");
	//��ӡ�к��к�
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
	printf("-------ɨ����Ϸ---------\n");
}


//��������
void setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = 10;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';//�����ʾ�ײ��ý�ȥ��
			count--;
		}
	}

}




//�Ų�����
//һ.get_mine_count()��������ͳ����������Χ�м����ף�
//��.FindMine()���ã�
//1. �����Ų������
//2. ������괦�ǲ�����
//(1) ���� - ���ź�ը���� - ��Ϸ����
//(2) ������ - ͳ��������Χ�м����� - �洢�Ų��׵���Ϣ��show���飬��Ϸ����

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
		printf("������Ҫ�Ų������:>");
		scanf("%d%d", &x, &y);//x--(1,9)  y--(1,9)

		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				displayboard(mine, row, col);
				break;
			}
			else
			{
				//����������£�ͳ��x,y������Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				//��ʾ�Ų������Ϣ
				displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("���겻�Ϸ�������������\n");
		}
	}

	if (win == row * col - 10)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		displayboard(mine, row, col);
	}
}