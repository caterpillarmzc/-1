#include "SeqList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//˳����ʼ��
void SeqListInit(PSeq ps, int capacity)
{
	ps->_array = (DataType*)malloc(sizeof(DataType)*capacity);
	if (NULL == ps->_array)
	{
		assert(0);
		return;
	}

	ps->_capacity = capacity;
	ps->_size = 0;
}
//β��
void SeqListPushBack(PSeq ps, DataType data)
{
#if 0
	assert(ps);

	// ˳�����
	// CheckCapacity(ps);

	ps->_array[ps->_size] = data;
	ps->_size++;
#endif

	SeqListInsert(ps, ps->_size, data);
}

//βɾ
void SeqListPopBack(PSeq ps)
{
#if 0
	assert(ps);
	if (SeqListEmpty(ps))
		return;

	ps->_size--;
#endif

	SeqListErase(ps, ps->_size - 1);
}

//ͷ��
void SeqListPushFront(PSeq ps, DataType data)
{
#if 0
	assert(ps);
	// CheckCapacity(ps);

	// ��˳��������е�Ԫ��ͳһ������һ��λ��
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_array[i+1] = ps->_array[i];
	}

	// ����Ԫ��
	ps->_array[0] = data;
	ps->_size++;
#endif

	SeqListInsert(ps, 0, data);
}

//ͷɾ
void SeqListPopFront(PSeq ps)
{
#if 0
	if (SeqListEmpty(ps))
		return;

	for (int i = 1; i < ps->_size; ++i)
		ps->_array[i-1] = ps->_array[i];

	ps->_size--;
#endif

	SeqListErase(ps, 0);
}

//ָ��λ��pos����ֵΪdata��Ԫ��
void SeqListInsert(PSeq ps, int pos, DataType data)
{
	assert(ps);
	if (pos < 0 || pos > ps->_size)
		return;

	CheckCapacity(ps);

	for (int i = ps->_size - 1; i >= pos; i--)
		ps->_array[i+1] = ps->_array[i];

	ps->_array[pos] = data;
	ps->_size++;
}

//ָ��λ��posɾ��
void SeqListErase(PSeq ps, int pos)
{
	assert(ps);
	if (pos < 0 || pos >= ps->_size)
		return;

	for (int i = pos + 1; i < ps->_size; ++i)
		ps->_array[i-1] = ps->_array[i];

	ps->_size--;
}

//����
int SeqListFind(PSeq ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
			return i;
	}

	return -1;
}

// ˳�������ЧԪ�صĸ��� 
int SeqListSize(PSeq ps)
{
	assert(ps);
	return ps->_size;
}

// ˳�����ܴ�С 
int SeqListCapacity(PSeq ps)
{
	assert(ps);
	return ps->_capacity;
}

int SeqListEmpty(PSeq ps)
{
	assert(ps);
	return 0 == ps->_size;
}

void SeqListClear(PSeq ps)
{
	assert(ps);
	ps->_size = 0;
}

// �Ƴ���һ��ֵΪdata��Ԫ��
// 1  2  3   2   2  4   1  2   2
void SeqListRemove(PSeq ps, DataType data)
{
	SeqListErase(ps, SeqListFind(ps, data));
}

// 1  2  3   2   2  4   1  2   2
// �Ƴ�����ֵΪdata��Ԫ��
void SeqListRemoveAll(PSeq ps, DataType data)
{
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}

	ps->_size -= count;
	/*
	int pos = -1;
	while (-1 != (pos = SeqListFind(ps, data)))
	{
		SeqListErase(ps, pos);
	}
	*/


}
//�ͷ�
void SeqListDestroy(PSeq ps)
{
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

//����
void CheckCapacity(PSeq ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		// ˳������Ѿ�û�пռ���
		int newCapacity = ps->_capacity * 2;

		// realloc(p, size)
		// �����¿ռ�
		int* pTemp = (DataType*)malloc(newCapacity*sizeof(DataType));
		if (NULL == pTemp)
		{
			assert(0);
			return;
		}

		// ����Ԫ�� memcpy
		for (int i = 0; i < ps->_size; ++i)
			pTemp[i] = ps->_array[i];

		// �ͷžɿռ�
		free(ps->_array);

		// ����
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

//��ӡ˳���
void SeqListPrint(PSeq ps)
{
	for (int i = 0; i < ps->_size; ++i)
		printf("%d ", ps->_array[i]);
	printf("\n");
}


////////////////////////////////////////////
// 
//��������(����)
void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

//ð������
void BubbleSort(PSeq ps)
{
	// N---->N-1
	for (int i = 0; i < ps->_size - 1; ++i) // ����ð���ܵ�����
	{
		int Ischange = 0;
		// ð�ݵľ��巽ʽ�������ڵ�����Ԫ�ؽ��бȽϣ� ������Ҫ����
		for (int j = 1; j < ps->_size - i; ++j)
		{
			if (ps->_array[j-1] > ps->_array[j])
			{
				Ischange = 1;
				Swap(&ps->_array[j-1], &ps->_array[j]);
			}
		}

		if (!Ischange)
			return;
	}
}


//���ֲ���
int SeqListBInarySearch(PSeq ps,DataType data)
{
	assert(ps);
	size_t left = 0;
	size_t right = ps->_size - 1;
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (ps->_array[mid]==data)
		{
			return mid;
		}
		if (ps->_array[mid]>x)
		{
			right = mid - 1;
		}
		if (ps->_array[mid]<x)
		{
			left = mid + 1;
		}
	}
	return -1;
}





//���Գ���
void TestSeqList()
{
	SeqList s;
	int pos = -1;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 2);
	printf("size = %d\n", SeqListSize(&s));
	printf("capacity = %d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListRemoveAll(&s, 2);
	SeqListPrint(&s);

	SeqListPushBack(&s, 1);
	printf("size = %d\n", SeqListSize(&s));
	printf("capacity = %d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s, 1, 5);
	SeqListPrint(&s);

	pos = SeqListFind(&s, 5);
	if (pos != -1)
		printf("5 is in %d!!!\n", pos);
	else
		printf("5 is not in %d!!!\n", pos);

	SeqListErase(&s, 1);

	pos = SeqListFind(&s, 5);
	if (pos != -1)
		printf("5 is in %d!!!\n", pos);
	else
		printf("5 is not in %d!!!\n", pos);

	SeqListPrint(&s);
	printf("size = %d\n", SeqListSize(&s));
	printf("capacity = %d\n", SeqListCapacity(&s));

	SeqListDestroy(&s);
}