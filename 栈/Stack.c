#include "Stack.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//���ռ䲢����
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)//��ЧԪ�ظ������������������
	{
		// �����¿ռ�,�ռ��СΪ2��
		int newCapacity = ps->_capacity * 2;
		SDataType* pTemp = (SDataType*)malloc(sizeof(SDataType)*newCapacity);
		if (NULL == pTemp)
		{
			assert(0);
			return;
		}

		// ����Ԫ��
		for (int i = 0; i < ps->_size; ++i)
			pTemp[i] = ps->_array[i];

		// �ͷžɿռ�
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

//ջ�ĳ�ʼ��
void StackInit(Stack* ps)
{
	assert(ps);//��֤ջ����
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 3);//����ռ�,3Ϊ��ʱ���Ŀռ��С
	if (NULL == ps->_array)//�жϿռ��Ƿ�����ɹ�
	{
		assert(0);
		return;
	}

	ps->_capacity = 3;//3Ϊ�ռ��С
	ps->_size = 0;//ʵ���ϻ�û�д洢Ԫ��
}

//��ջ(��ջ�ڲ���Ԫ��)
void StackPush(Stack* ps, SDataType data)
{
	// ����Ƿ����㹻�ռ�
	CheckCapacity(ps);//��߻�������ռ�ĺ���

	ps->_array[ps->_size++] = data;//����һ��Ԫ�غ�sizeҪ++
}

//��ջ(ɾ��ջ��Ԫ��)
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))//���ջΪ�յĻ��޷�����ɾ������,ֱ�ӷ���
		return;

	ps->_size -= 1;//ջ��Ϊ��,Ԫ�ظ�������һ��
}

//��ȡջ��Ԫ��ps
SDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];//ջ��ָ���Ԫ�������һ��Ԫ�ص�λ�ü�һ
}

//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_size;//����size��ֵ��Ϊ����
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_size;//�ж��Ƿ���Ԫ��
}

//ջ������(�����ڴ�й©)
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_array)//��psָ���ջ�Ŀռ��ͷ�
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackDestroy(&s);
}