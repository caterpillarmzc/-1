//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("***********************************\n");
//	printf("***********  1.��ʼ��Ϸ ***********\n");
//	printf("***********  0.������Ϸ ***********\n");
//	printf("***********************************\n");
//}
//
//void game()
//{
//	int i = 0;
//	int ret = 0;
//	ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("������1-100�����֣�");
//		scanf("%d", &i);
//		if (i>ret)
//		{
//			printf("����\n");
//		}
//		else if (i<ret)
//		{
//			printf("����\n");
//		}
//		else
//		{
//			printf("��ϲ�㣡�¶���\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("��Ϸ����\n");
//			break;
//		default:
//			printf("������������������\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}





/*//д����������������������в�����Ҫ�����֣� 
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
#include<stdio.h>
#include<stdlib.h>
int main(){
	int arr[] = { 7, 8, 9, 10, 11 };
	int to_find = 7;
	int left = 0;
	int mid = 0;
	//�ܵ��ֽ���/һ����ռ���ֽ���,�ټ�һ��Ϊ���һ�����±�
	int right =  sizeof(arr) /sizeof(arr[0]-1);
	while (left <= right){
		int mid = (left + right) / 2;
		if (to_find > arr[mid]){
			left = mid + 1; 
		}
		else if (to_find < arr[mid]){
			right = mid - 1;
		}
		else{ 
			break;
		}
	}
	if (left <= right){
		printf("�ҵ���,�±�Ϊ:%d\n", mid);
	}
	else{
		printf("-1\n");
	}
	system("pause");
	return 0;

}*/



//��д����ģ��������������ĳ����� 
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h> 
//#include<windows.h>
//int main()
//{
//	int psw[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; ++i)
//	{
//		printf("����������:");
//		scanf("%s", psw);
////strcmp�����������Ƚ�2���ַ����ĺ�����
////��srcmp�����������1���ַ���2�����ӵ�һ���ַ���ʼ�Ƚϣ�
////�������������ַ�����ȫ��ͬ����strcmp�������������ֵΪ0��
////����ʼ���ֲ�ͬ���ַ�����������ַ�ASCII����бȽϣ����ַ���1��ASSCIIֵ����2
////�����ֵ ���� 0����֮�����ֵ С�� 0��
//		
//		if (strcmp("123456", psw) == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("����������������˳�ϵͳ��\n");
//	}
//	system("pause");
//	return 0;
//}




//��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//void main()
//{
//	char c = 'a';
//	printf("������һ�������ַ�c:");
//	scanf("%c", &c);
//	if (c >= 'A' && c <= 'Z')
//	{
//		c = c + 32;
//	}
//	else if (c >= 'a' && c <= 'z')
//	{
//		c = c - 32;
//	}
//	printf("%c\n", c);
//	system("pause");
//}
