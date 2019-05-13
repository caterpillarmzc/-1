#include <stdio.h>

int BinSearch_Recursion(int Array[], int low, int high, int key);

//�ݹ鷽��
int BinSearch_Recursion(int Array[], int len, int key)
{
	//������������Ϊ�ջ������鳤��<=0��ô�ͷ���-1�������Ա��
	if (Array == NULL || len <= 0)
		return -1;
	return BinSearch_Recursion(Array, 0, len - 1, key);
}

int BinSearch_Recursion(int Array[], int low, int high, int key)  /*��������ֱ����ҵ�������Array��������ʼλ�ã��������λ�ã�Ҫ�ҵ�����*/
{
	if (low <= high)
	{
		//int mid = (low+high)/2;  
		int mid = low + (high - low) / 2;//Ϊ�˷�ֹ�������
		if (key == Array[mid])
			return mid;
		else if (key<Array[mid])
			return BinSearch_Recursion(Array, low, mid - 1, key);
		else if (key>Array[mid])
			return BinSearch_Recursion(Array, mid + 1, high, key);
	}
	else
		return -1;
}

//�ǵݹ鷽��
int BinSearch(int Array[], int len, int key)  /*��������ֱ��������ַArray�����鳤��len��Ҫ�ҵ�����key  ����ֵΪkey��λ��*/
{
	//�����Ա��
	if (Array == NULL || len <= 0)
		return -1;

	int low = 0, high = len - 1;
	int mid;
	while (low <= high)
	{
		//mid = (low+high)/2;  
		mid = low + (high - low) / 2;//Ϊ�˷�ֹ�������
		if (key == Array[mid])
			return mid;
		if (key<Array[mid])
			high = mid - 1;
		if (key>Array[mid])
			low = mid + 1;
	}
	return -1;
}

int main(void)
{
	int a[6] = { 0, 5, 20, 30, 88.102 };
	int len = sizeof(a) / sizeof(a[0]);
	int locate = 0, locate_recursion;
	locate = BinSearch(a, len, 88);
	locate_recursion = BinSearch_Recursion(a, len, 20);//���ݲ�������ѡ��ִ�еĺ���
	printf("%d  %d\n", locate, locate_recursion);
	return 0;
}
