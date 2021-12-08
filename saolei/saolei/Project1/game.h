#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//创建棋盘
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘
void initboard(char board[ROWS][COLS], int rows, int cols,char set);
//打印棋盘
void displayboard(char board[ROWS][COLS], int row, int col);
//布置雷
void setmine(char mine[ROWS][COLS], int row, int col);
//排查雷
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);