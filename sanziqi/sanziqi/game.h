//game.hͷ�ļ�������������ã����Ŷ����Լ����ຯ������
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//���Ŷ���
#define ROW 3
#define COL 3

//��������

//��ʼ������
void initboard(char board[ROW][COL], int row, int col);
//��ӡ����
void displayboard(char board[ROW][COL], int row, int col);
//����ƶ�
void playermove(char board[ROW][COL], int row, int col);
//��������
void computermove(char board[ROW][COL], int row, int col);
// 1.���Ӯ��-*
//2.����Ӯ��-#
//3.ƽ��-Q
//4.��Ϸ����-c
char iswin(char board[ROW][COL], int row, int col);