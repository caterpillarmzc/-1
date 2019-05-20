#pragma once

// ˳���ṹ��
// ����
// ��̬˳���
#if 0
typedef int DataType;
#define MAX_SIZE 100

struct SeqList
{
	DataType _array[MAX_SIZE];  // �����洢˳����е�Ԫ��
	int _size;   // ˳�������ЧԪ�صĸ���
};
#endif


// ��̬��˳���
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity;   // ˳�����ܴ�С
	int _size;       // ˳�������ЧԪ�صĸ���
}SeqList, *PSeq;

//typedef struct SeqList SeqList;
//typedef struct SeqList* PSeqList;

void SeqListInit(PSeq ps, int capacity);
void SeqListPushBack(PSeq ps, DataType data);
void SeqListPopBack(PSeq ps);
void SeqListPushFront(PSeq ps, DataType data);
void SeqListPopFront(PSeq ps);
void SeqListInsert(PSeq ps, int pos, DataType data);
void SeqListErase(PSeq ps, int pos);
int SeqListFind(PSeq ps, DataType data);
int SeqListEmpty(PSeq ps);
int SeqListSize(PSeq ps);
int SeqListCapacity(PSeq ps);
void SeqListClear(PSeq ps);
void SeqListRemove(PSeq ps, DataType data);
void SeqListDestroy(PSeq ps);
void CheckCapacity(PSeq ps);

//////////////////////////////////////////






void TestSeqList();
