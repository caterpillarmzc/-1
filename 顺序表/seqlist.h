#pragma once
////��̬˳���
////˳��������,���ڱ����ڼ�ȷ��
//struct SeqList 
//{
//	int array[100];//������100
//	int size;//˳���ʵ�ʴ洢�����ݸ���
//}; SeqList;

//��̬˳���
//����ʱ��ȷ����(����ʱ��)
typedef struct SeqList{
	int *array;
	int capacity;//����
	int size;
}SeqList;

//��ʼ��
void SeqListInit(SeqList*ps,int capacity);
//����
void SeqListDestroy(SeqList *ps);