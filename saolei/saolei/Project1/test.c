#include"game.h"
void menu()
{
	printf("*********************\n");
	printf("****   1.play  ******\n");
	printf("****   0.exit  ******\n");
	printf("*********************\n");
}
//��Ϸ�����ʵ��
void game()
{
	char mine[ROWS][COLS] = {0};//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = {0};//����Ų�����׵���Ϣ
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS,'*');//��ʼ������
	displayboard(show, ROW, COL);//��ӡ����
	setmine(mine, ROW, COL);//������
	displayboard(mine, ROW, COL);
	findmine(mine,show, ROW, COL);//�Ų���
}

//��Ϸ�˵�����
//������
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//������Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("ѡ���������ѡ��\n");
			break;

		}
	} while (input);
	return 0;
}