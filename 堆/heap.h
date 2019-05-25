#pragma once

typedef int HPDataType;

//ͨ������ָ�봫�εķ���ѡ�񴴽���ѻ���С��
typedef int(*PCOM)(HPDataType, HPDataType);
int Less(HPDataType left, HPDataType right);
int Greater(HPDataType left, HPDataType right);

typedef struct Heap
{
	HPDataType* _array;//ָ��һ�������Ŀռ�
	int _capacity;//����
	int _size;//��ЧԪ�ظ���
	PCOM Compare;
}Heap;

void InitHeap(Heap* hp, HPDataType* array, int size,PCOM compare);

void TestHeap();
void AdjustDown(int	*array, int size, int parent);
void InsertHeap(Heap* hp, HPDataType data);
void EraseHeap(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
HPDataType HeapTop(Heap* hp);//��ȡ�Ѷ�Ԫ��
void DestroyHeap(Heap* hp);
void HeapSort(int* array, int size);