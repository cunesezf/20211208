//����ģ��
#include<stdio.h>
#include"game.h"
void game()
{
	//�洢����-��ά���鴴��
	char board[ROW][COL];
	initboard(board, ROW, COL);//��ʼ������-��ʼ���ո�
	displayboard(board, ROW, COL);//��ӡһ�����̣��������Ǵ�ӡ��������
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		//�������
		 playermove(board, ROW, COL);
		 displayboard(board, ROW, COL);
		 //�ж�����Ƿ�Ӯ����Ϸ
		 ret=iswin(board, ROW, COL);
		 if (ret!= 'C')
		 {
			 break;
		 }
		//��������
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
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	
}
void menu()
{
	printf("*********************\n");
	printf("***1.��ʼ��0.����****\n");
	printf("*********************\n");
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("������Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}