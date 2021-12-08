//game.h头文件：包含库的引用，符号定义以及各类函数声明
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//符号定义
#define ROW 3
#define COL 3

//函数声明

//初始化棋盘
void initboard(char board[ROW][COL], int row, int col);
//打印棋盘
void displayboard(char board[ROW][COL], int row, int col);
//玩家移动
void playermove(char board[ROW][COL], int row, int col);
//电脑下棋
void computermove(char board[ROW][COL], int row, int col);
// 1.玩家赢了-*
//2.电脑赢了-#
//3.平局-Q
//4.游戏继续-c
char iswin(char board[ROW][COL], int row, int col);