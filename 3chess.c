//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<Windows.h>
////��������Ϸ
//#define MAX_row 3
//#define MAX_col 3
//
//void menu() {
//	printf("*********************************************\n");
//	printf("**************      ��Ϸ�˵�      ***********\n");
//	printf("**************  1.��ʼ��������Ϸ  ***********\n");
//	printf("**************  0.�˳���Ϸ�˵���  ***********\n");
//	printf("*********************************************\n");
//}
//
//void init(char c[MAX_row][MAX_col]) {
//	for (int row = 0; row < MAX_row; row++) {
//		for (int col = 0; col < MAX_col; col++) {
//			c[row][col] = ' ';
//		}
//	}
//}
//
//void printC(char c[MAX_row][MAX_col]) {
//	printf("+---+---+---+\n");
//	for (int row = 0; row < MAX_row; row++) {
//		printf("| ");
//		for (int col = 0; col < MAX_col; col++) {
//			printf("%c | ", c[row][col]);
//		}
//		printf("\n+---+---+---+\n");
//	}
//}
//
//void playC(char c[MAX_row][MAX_col]) {
//	int row = 0;
//	int col = 0;
//	printf("�������������\n");
//	while (1) {
//		printf("��������Ҫ�µ�λ�� row col ��");
//		scanf("%d %d", &row, &col);
//		if ( row<0||row >= MAX_row ||col<0|| col >= MAX_col) {
//			printf("���µ���������ȥ��\n");
//			continue;
//		}
//		if (c[row][col] != ' ') {
//			printf("��Ҫ�µ�λ���Ѿ���ռ��\n");
//			continue;
//		}
//		c[row][col] = '*';
//		break;
//	}
//}
//void computerC(char c[MAX_row][MAX_col]) {
//	srand((unsigned int)time(0));
//	while (1) {
//		int row = rand() % MAX_row;
//		int col = rand() % MAX_col;
//		if (c[row][col] != ' ') {
//			continue;
//		}
//		c[row][col] = '#';
//		break;
//	}
//}
//
//int isFull(char c[MAX_row][MAX_col]) {
//	for (int row = 0; row < MAX_row; row++) {
//		for (int col = 0; col < MAX_col; col++) {
//			if (c[row][col] == ' ') {
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//char isWinner(char c[MAX_col][MAX_col]) {
//	for (int row = 0; row < MAX_row; row++) {
//		if (c[row][0]!=' '&& c[row][0] == c[row][1] && c[row][1] == c[row][2]) {
//			return c[row][0];
//		}
//	}
//	for (int col = 0; col < MAX_col; col++) {
//		if (c[0][col]!=' '&& c[0][col] == c[1][col] && c[1][col]== c[2][col]) {
//			return c[0][col];
//		}
//	}
//	if (c[0][0] != ' ' && c[0][0] == c[1][1] && c[1][1] == c[2][2]) {
//		return c[0][0];
//	}
//	if (c[0][2] != ' ' && c[0][2] == c[1][1] && c[1][1] == c[2][0]) {
//		return c[0][2];
//	}
//	if (isFull(c) == 1) {
//		return 'p';
//	}
//	return ' ';
//}
//
//int main() {
//	while(1) {
//		//������Ϸ�˵�
//		menu();
//		int select = 0;
//		printf("���������ѡ��:");
//		scanf("%d", &select);
//		if(select==1){
//			//����3 x 3���ַ��;�����Ϊ����,
//			char chessBoard[MAX_row][MAX_col] = { 0 };
//			//��ʼ������,ÿһ��λ������Ϊ�ո�
//			init(chessBoard);
//			char result = ' ';
//			while (1) {
//				
//				//��ӡ����
//				printC(chessBoard);
//				//�������
//				playC(chessBoard);
//				//�ж�ʤ��
//				result = isWinner(chessBoard);
//				if (result != ' ') {
//					break;
//				}
//				//��������
//				computerC(chessBoard);
//				//�ж�ʤ��
//				result = isWinner(chessBoard);
//				if (result != ' ') {
//					break;
//				}
//				//��ӡ֮ǰ����
//				system("cls");
//			}
//			system("cls");
//			printC(chessBoard);
//			if (result == '*') {
//				printf("���ʤ�ˣ�\n\n");
//			}
//			else if (result == '#') {
//				printf("��Ұ��ˣ�\n\n");
//			}
//			else {
//				printf("��͵���δ�ֳ�ʤ����\n\n");
//			}
//			Sleep(1500);
//			//system("cls");
//		}
//		if (select == 0) {
//			printf("���˳���Ϸ����ӭ�´���Ϸ��\n");
//			break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}