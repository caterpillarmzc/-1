//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
//#include <stdio.h>
//#include <stdlib.h>
//void func(int *a,int size)
//{
//	int i = 0; //���Ԫ�ص��±�
//	int j = size - 1;//�ұ�Ԫ�ص��±�
//	for (i = 0; i != j;i++)
//	{if (a[i]%2!=0)//�ж�����ָ�����ż��
//	{
//		continue;
//	}
//	else
//	{
//		//����λ��
//		int t = a[i];
//		a[i] = a[j];
//		a[j] = t;
//		if (a[j]%2==0)
//		{
//			j--;
//		}
//		j--;
//	 }
//	}
//}
//
//int main(){
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9};
//	int size = sizeof(a) / sizeof(a[0]);//��ȡԪ�ظ���size
//	int i;
//	func(a, size);//���ú���
//	for (i = 0; i < size;i++)
//	{
//		printf("%d", a[i]);
//	}
//	system("pause");
//	return 0;
//}

//2.���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//#include <stdio.h>
//#include <stdlib.h>
//
//#define ROW 3
//#define COL 3
//int func(int arr[ROW][COL], int row, int col, int num)
//{
//	int left = 0;
//	int right = col - 1;
//	while ((left >= 0) && (right < col))
//	{
//		//����������С��num������һλ��
//		if (arr[left][right] < num)
//		{
//			left++;
//		}
//		//����������С��num��ǰ��һλ��
//		if (arr[left][right] > num)
//		{
//			right--;
//		}
//		if (arr[left][right] == num)
//		{
//			return 1;
//		}
//	}
//	return 0;
//
//}
//int main()
//{
//	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int key = 9;
//	int ret = func(arr, ROW, COL, key);
//	if (ret==1)
//	{
//		printf("�ҵ���\n");
//	}
//	if (ret==0)
//	{
//		printf("û�ҵ�\n");
//	}
//
//	system("pause");
//	return 0;
//}

