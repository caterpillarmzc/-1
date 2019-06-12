//��������,ȥ��׼ֵ,��ͬʱ���м俿£
//����������ֹͣ,�ұ�����С��ֹͣ
//������С����λ��,����ָ�뵽ͬһλ��ʱ,���׼ֵ����
//���ս����С..��׼ֵ..��

#include <stdio.h>
#include <stdlib.h>
//��׼ֵ��ȡ������ʱ,�������ʱ�临�ӶȺܸߵ����
//����ȡ�з�:ȡ������,����Ҷ�,�м�,ѡ���С�����м������Ϊ��׼ֵ
int GetMiddleIndex(int *array,int left,int right){
	int mid = left + ((right - left) >> 1);
	if (array[left]<array[right-1]){
		if (array[mid] < array[left])
			return left;
		else if (array[mid]>array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else{
		if (array[mid]>array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}



//���ŷ���1
int Partion1(int *array,int left,int right){
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);//�������׼ֵ�ĺ���
	Swap(&array[mid], &array[right - 1]);//�������ұ�Ԫ�����׼ֵ
	int key = array[right - 1];
	while (begin<end){
		//�������ұȻ�׼ֵ���Ԫ��,�ҵ���ֹͣ
		while (begin<end&&array[begin]<=key)
		{
			begin++;
		}
	}
}


//���ŷ���2
int Partion2(int* array,int left,int right){
	int cur = left;    //�˴��Ĵ�������û�׼ֵ��ѡȡ�Ż�
	int prer = cur;    //int mid=GetMiddleIndex(array,left,right);
	int key = array[right - 1];     //Swap(&array[mid],&array[right-1]);
	while (cur<right){
		if (array[cur] < key&&++prer != cur)
			Swap(&array[cur], &array[prer]);
		++cur;
	}
	if (++prer != right)
		Swap(&array[prer], &array[right - 1]);
	return prer;
}

//���ŷ���3---�ڿӷ�
//��׼ֵ����Ϊ���һ��ֵ,�� key=array[right-1]
//��λΪbegin,ĩβΪend
//����׼ֱ����,endΪ��,��ǰ����ѵ�һ������key��ֵ����end
//��end��ʼ��ǰ����,�ҵ���keyС����begin�Ŀ�,ѭ��ֱ������
//����key���������Ŀ�

int Partion3(int* array,int left,int right){
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin<end){   //��ǰ�����ұ�key���Ԫ��,�ҵ������end
		while (array[begin] <= key)
			begin++;
		if (begin<end){//���endλ�õĿ�
			array[end] = array[begin];
			end--;
		}
		while (begin < end&&array[end] >= key)  //�Ӻ���ǰ�ұȻ�׼ֵС��Ԫ��,�ҵ������begiin
			end--;
		if (begin<end){
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;
}



//�����������ַ���
void QuickSort(int* array,int left,int right){
	if (right-left>1){
		int div = Partion1(array, left, right);//���ջ�׼ֵ������ָ������������,С��..��׼..����
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

//�õݹ�ķ�ʽ��������
void QuickSort(int*array,int left,int right){
	if (right - left < 16)
		InsertSort(array, right - left);//Ԫ�ظ���С��16ʱ,�ò����������Ч��
	else{
		int div = Partion1(array, left, right);//���ջ�׼ֵ������ָ������������,С��..��׼..����
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}//�ռ临�Ӷ�O(NlogN)   NΪ�ݹ����


//��ѭ���ķ�ʽ��������--�õ�ջ
#include "Stack.h"
void QuickSortNor(int *array,int size){
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);  //ѹջ,��ѹ��,��ѹ��,ȡ��ʱ��ȡ��
	StackPush(&s, left);
	while (!StackEmpty(&s)){//��ջ��Ϊ��
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);
		if (right-left>1){//�������С��1,��ѭ������
			int div = Partion1(array, left, right);
			//��������[left,div)��[div+1,right)
			StackPush(&s, right);//�����Ұ�����
			StackPush(&s, div+1);
			StackPush(&s, div);//�����������
			StackPush(&s, left);

		}
	}
}