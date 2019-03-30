#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu(){
	printf("=========================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("=========================\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d",&choice);
	return choice;
}
//�궨���к���,�ɶ��Ը�,����Ĳ���
#define MAX_ROW 3
#define MAX_COL 3
char chess_board[MAX_ROW][MAX_COL];


//�Զ���ʽ�ĳ��򿪷�����
void Init(){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chess_board[row][col] = ' ';
		}
	}
	//�����������
	srand((unsigned int)time(0));
}

void Print(){
	for (int row = 0; row < MAX_ROW; ++row){
		printf("%c|%c|%c\n", chess_board[row][0],
			chess_board[row][1],chess_board[row][2]);
		if ("row!= MAX_ROW-1"){
			printf(" --- --- --- \n");
		}
	}
	//system("pause");
}

void PlayerMove(){
	printf("�������!\n");
	while (1){
		printf("����������λ�õ�����(row,col):");
		int row = 0;
		int col = 0;
		scanf("%d,%d", &row, &col);
		//��������Ƿ�Ϸ�
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COL){
			printf("����Ƿ�,��������\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("�����ѱ�ռ��!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("����������!\n");
}

void ComputerMove(){
	printf("��������!\n");
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("�����������!\n");
}

//�����������,����1,���򷵻�0
int IsFull(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; col++){
			if (chess_board[row][col] == ' '){
				//δ��
				return 0;
			}
		}
	}return 1;
}
//����ֵ��ʾʤ������˭
//x��ʾ���ʤ��
//o��ʾ����ʤ��
//q��ʾ����
//' '��ʾδ��ʤ��
char  CheckWinner(){
	{
		//����������Ƿ�����һ����
		for (int row = 0; row < MAX_ROW; ++row){
			if (chess_board[row][0] == chess_board[row][1]
				&& chess_board[row][0] == chess_board[row][2])
				return chess_board[row][0];
		}
	}
	//����������Ƿ�����һ����
	for (int col = 0; col = MAX_COL; ++col){
		if (chess_board[0][col]== chess_board[1][col]
			&& chess_board[0][col]== chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//������жԽ����Ƿ�����һ����
	if (chess_board[0][0] == chess_board[1][1] &&
		chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] &&
		chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	//����������δ�ֳ�ʤ��
	if (IsFull()){
		return'q';
	}
	return ' ';

}
void game(){
//1.��ʼ������
	Init();
	char winner = ' ';
	while (1){
		// 2.��ӡ����
		Print();
		//3.�������
		PlayerMove();
		//4.���ʤ��
		winner =CheckWinner();
		if (winner != ' '){
		//ʤ���ѷ�
			break;
		}
		//5.��������
		ComputerMove();
		//6.���ʤ���󷵻ص�2����ѭ��
		winner = CheckWinner();
		if (winner != ' '){
			//ʤ���ѷ�
			break;
		}
	}
	Print();
	if (winner == 'x'){
		printf("��Ӯ��!\n");
	}
	else if (winner == 'o'){
		printf("�����,�����Զ��򲻹�\n");
	}
	else if (winner == 'q'){
		printf("���͵������忪!\n");
	}
	else{
		printf("�������bug��!\n");
	}
}




int main(){
	while (1){
		int choice = menu();
		if (choice ==1){
			game();
		} 
		else if (choice == 0)
		{
			printf("good bye!");
			break;
		}
		else{
			printf("������������!");
		}
	}
	
	system("pause");
	return 0;
}