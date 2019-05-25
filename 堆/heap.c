#include "heap.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>


//��ʼ��
void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare)
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType));
	if (NULL==hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;

	for (int i = 0; i < size;++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	//���ݴ���Ĳ���ѡ���ѻ���С��
	hp->Compare = compare;
	//������ȫ������������������ѵ�����
	//�������һ�����size-1,�����ҵ���˫��((size-1)-1)/2,
	//��Ϊ���һ����Ҷ�ڵ��λ��
	int root  = ((size - 2) >> 1);
	//ÿ�ε����Ķ�����parentΪ��root����
	for (; root >= 0;--root)
	{
		AdjustDown(hp->_array, size, root,hp->Compare);
	}

}//ע��:��Ԫ�ط�������ڵĿռ��,��һ������ѵ�����


//����ռ䲢��Ԫ�طŽ�ȥ
void Swap(HPDataType* pleft, HPDataType* pright)
{
	HPDataType temp = *pleft;
	*pleft = *pright;
	*pright = temp;
}


//���ִ�����Ѻ�С�ѵķ���
int Less(HPDataType left, HPDataType right)
{
	return left < right;
}
int Greater(HPDataType left, HPDataType right)
{
	return left > right;
}


//���ϵ���
void AdjustUp(HPDataType* array,int size,int child,PCOM Compare)
{
	int parent = (child - 1) / 2;
	while(child)//��child���˸��ڵ��λ��ʱ,ѭ������
	{

		if (Compare(array[child] , array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			return;
	}
}


//���µ���
void AdjustDown(HPDataType* array, int size, int parent, PCOM Compare)//��Ҫ�����Ľڵ���Ϊparent
{
	//Ĭ����child���parent������,
	//��ȫ������ĳ���ڵ����ֻ��һ������,��һ��������
	int child = parent * 2 + 1;

	while (child < size)
	{
		//˫�׸���С�ĺ��ӱȽ�,������
		//��Ѱ�ҽ�С�ĺ���
		if (child + 1 < size&&Compare(array[child + 1], array[child]))
		{
			child += 1;
		}
		if (Compare(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}


//����
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size==hp->_capacity)
	{
		//�����¿ռ�
		int newCapacity = hp->_capacity * 2;
		HPDataType* pTemp = (HPDataType*)malloc(sizeof(HPDataType)*newCapacity);
		if (NULL==pTemp)
		{
			assert(0);
			return;
		}
		//����Ԫ��
		for (int i = 0; i < hp->_size;++i)
			pTemp[i] = hp->_array[i];
		//�ͷſռ�
		free(hp->_array);
		hp->_array = pTemp;
		hp->_capacity = newCapacity;
	}
}


//�ѵĲ���,����Ԫ��data
//���뵽���һ���ڵ���
//��Ҫ�жϿռ��Ƿ񹻲���
//һ����������,ÿ�ζ���˫�׽ڵ�ȽϽ���(��Ϊ���ϵ���)
void InsertHeap(Heap* hp, HPDataType data)
{
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	AdjustUp(hp->_array, hp->_size, hp->_size - 1,hp->Compare);
}


//�ѵ�ɾ��--һ����ɾ���Ѷ�Ԫ��
void EraseHeap(Heap* hp)
{
	if (HeapEmpty(hp))
		return;
	//�Ѷ�Ԫ�������һ���ڵ㽻��λ��,size�ټ�Сһ���ռ�,
	//���൱��ɾ��,ɾ����ɺ��ٽ��е���
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size -= 1;
	AdjustDown(hp->_array, hp->_size, 0, hp->Compare);
}


//�ж϶�����ЧԪ�ظ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}


//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}


//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}


//���ռ��ͷ�
void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

//����Ϊ���
void HeapAdjust(int* array,int size,int parent)
{
	int child = parent * 2 + 1;
	while(child<size)
	{
		//�����Һ����н�С��һ��
		if (child + 1 < size&&array[child + 1] > array[child])
			child += 1;
		if(array[child]>array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int* array, int size)
{
	//����---��� С��
	//�紴�����,�ҵ����һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root)
		HeapAdiust(array, size, root);
	//����
	int end = size - 1;
	while (end)//��end=0�ǽ�ֹ
	{
		//�Ѷ�Ԫ�������һ��Ԫ�ؽ���λ��,
		//ɾ���ѵ׵����һ��Ԫ��,��Ԫ�ؼ�1,�����µ���,ѭ��
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}

}
//���Գ���
void TestHeap()
{
	Heap hp;
	int array[] = { 2,3,8,0,9,1,7,4,6,5 };
	InitHeap(&hp, array, sizeof(array)/sizeof(array[0]),Less);
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));
	EraseHeap(&hp);
	printf("%d\n", HeapTop(&hp));
	InsertHeap(&hp, 0);
	printf("%d\n", HeapTop(&hp));
	DestroyHeap(&hp);
}

