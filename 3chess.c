#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
//三子棋游戏
#define MAX_row 3
#define MAX_col 3

void menu() {
	printf("*********************************************\n");
	printf("**************      游戏菜单      ***********\n");
	printf("**************  1.开始三子棋游戏  ***********\n");
	printf("**************  0.退出游戏菜单！  ***********\n");
	printf("*********************************************\n");
}

void init(char c[MAX_row][MAX_col]) {
	for (int row = 0; row < MAX_row; row++) {
		for (int col = 0; col < MAX_col; col++) {
			c[row][col] = ' ';
		}
	}
}

void printC(char c[MAX_row][MAX_col]) {
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_row; row++) {
		printf("| ");
		for (int col = 0; col < MAX_col; col++) {
			printf("%c | ", c[row][col]);
		}
		printf("\n+---+---+---+\n");
	}
}

void playC(char c[MAX_row][MAX_col]) {
	int row = 0;
	int col = 0;
	printf("请玩家落子下棋\n");
	while (1) {
		printf("请输入你要下的位置 row col ：");
		scanf("%d %d", &row, &col);
		if ( row<0||row >= MAX_row ||col<0|| col >= MAX_col) {
			printf("您下到棋盘外面去了\n");
			continue;
		}
		if (c[row][col] != ' ') {
			printf("您要下的位置已经被占领\n");
			continue;
		}
		c[row][col] = '*';
		break;
	}
}
void computerC(char c[MAX_row][MAX_col]) {
	srand((unsigned int)time(0));
	while (1) {
		int row = rand() % MAX_row;
		int col = rand() % MAX_col;
		if (c[row][col] != ' ') {
			continue;
		}
		c[row][col] = '#';
		break;
	}
}

int isFull(char c[MAX_row][MAX_col]) {
	for (int row = 0; row < MAX_row; row++) {
		for (int col = 0; col < MAX_col; col++) {
			if (c[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char isWinner(char c[MAX_col][MAX_col]) {
	for (int row = 0; row < MAX_row; row++) {
		if (c[row][0]!=' '&& c[row][0] == c[row][1] && c[row][1] == c[row][2]) {
			return c[row][0];
		}
	}
	for (int col = 0; col < MAX_col; col++) {
		if (c[0][col]!=' '&& c[0][col] == c[1][col] && c[1][col]== c[2][col]) {
			return c[0][col];
		}
	}
	if (c[0][0] != ' ' && c[0][0] == c[1][1] && c[1][1] == c[2][2]) {
		return c[0][0];
	}
	if (c[0][2] != ' ' && c[0][2] == c[1][1] && c[1][1] == c[2][0]) {
		return c[0][2];
	}
	if (isFull(c) == 1) {
		return 'p';
	}
	return ' ';
}

int main() {
	while(1) {
		//设置游戏菜单
		menu();
		int select = 0;
		printf("请输入你的选择:");
		scanf("%d", &select);
		if(select==1){
			//创建3 x 3的字符型矩阵作为棋盘,
			char chessBoard[MAX_row][MAX_col] = { 0 };
			//初始化棋盘,每一个位置设置为空格
			init(chessBoard);
			char result = ' ';
			while (1) {
				
				//打印棋盘
				printC(chessBoard);
				//玩家下棋
				playC(chessBoard);
				//判断胜负
				result = isWinner(chessBoard);
				if (result != ' ') {
					break;
				}
				//电脑下棋
				computerC(chessBoard);
				//判断胜负
				result = isWinner(chessBoard);
				if (result != ' ') {
					break;
				}
				//打印之前清屏
				system("cls");
			}
			system("cls");
			printC(chessBoard);
			if (result == '*') {
				printf("你获胜了！\n\n");
			}
			else if (result == '#') {
				printf("你惨败了！\n\n");
			}
			else {
				printf("你和电脑未分出胜负！\n\n");
			}
			Sleep(1500);
			//system("cls");
		}
		if (select == 0) {
			printf("已退出游戏！欢迎下次游戏。\n");
			break;
		}
	}

	system("pause");
	return 0;
}
