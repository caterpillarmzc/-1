#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int menu(){
	printf("=========================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("=========================\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//�궨���к���,�ɶ��Ը�,����Ĳ���
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]){
//����show��˵,����Ϊ*
	for (int row = 0; row < MAX_ROW;++row){
		for (int col = 0; col < MAX_COL;++col){
			show_map[row][col] = '*';
	    }
	}
	//����mine_map,��Ҫ����������ɸ�����
	//0��ʾ���ǵ���,1��ʾ�ǵ���
	for (int row = 0; row < MAX_ROW;++row){
		for (int col = 0; col < MAX_COL;++col){
			mine_map[row][col] = '0';
	    }
	}
	int n = MINE_COUNT;
	while (n>0)
	{
		int row=rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col]=='1')
		{//��ʾ��λ���Ѿ��ǵ�����,��Ҫ��������
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}
void PrintMap(char map[MAX_ROW][MAX_COL]){
//��ӡ��ͼ������
	//��һ��
	printf("    ");
	for (int i = 0; i < MAX_COL;i++){
		printf("%d ", i);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL-2;++col){
		printf("---");
	}
	printf("\n");
	//��ӡ������
	for (int row = 0; row < MAX_ROW;++row){
		printf(" %d| ",row);
		//��ӡ���е�ÿһ��
		for (int col = 0; col < MAX_COL;++col){
			printf("%c ",map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(int row,int col,
	char show_map[MAX_ROW][MAX_COL], 
	char mine_map[MAX_ROW][MAX_COL]){
	//���ݵ�ǰ��λ���ж���Χ�м�������
	//���ҽ�������ָ��µ�show_map

}
void game(){
	//������ͼ(��ҿ����ĺ���ʾλ�õ�)
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	Init(show_map, mine_map);
	//�Ѿ������Ŀո���(�ǵ�����)
	int blank_count_already_show = 0;
	while (1){
		//��ӡ��ͼ
		PrintMap(show_map);
		//�������겢�Ϸ��Լ��
		printf("������һ������(row,col):");
		int row = 0;
		int col = 0;
		scanf("%d,%d", &row, &col);
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COL){
			printf("��������,����������");
			continue;
		}
		if (show_map[row][col]!='*'){
			printf("�������λ���Ѿ���������\n");
			continue;
		}
		//�ж��Ƿ��ǵ���
		if (mine_map[row][col] == '1'){
			printf("��Ϸ����\n");
			PrintMap(mine_map);
			break;
		}
		//�ж���Ϸ�Ƿ�ʤ��
		//�ж����зǵ���λ�ö�������
		++blank_count_already_show;
		if (blank_count_already_show==
			MAX_ROW*MAX_COL-MINE_COUNT){
			printf("��Ϸʤ��\n");
			PrintMap(mine_map);
			break;
		}
		//ͳ����Χ�׵ĸ���
		UpdateShowMap(row,col,show_map,mine_map);
	}
}
int main(){
	while (1){
		int choice = menu();
		if (choice == 1){
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