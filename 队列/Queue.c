#include "Queue.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
//��ʽ�ṹʵ�ֶ���,�õ��������β���ͷɾ

//����ռ�
QNode* BuyQueueNode(QDataType data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == pNewNode)//�ж��Ƿ�����ɹ�
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

//���еĳ�ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;//�����Ķ���Ϊ��,��Ԫ��
}

//�����(��β��)
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* pNewNode = BuyQueueNode(data);
	if (QueueEmpty(q))//�������Ϊ��,��ͷ��β��ָ����ǲ�����½ڵ�
		q->_front = q->_back = pNewNode;
	else
	{
		q->_back->_pNext = pNewNode;//�������һ��������һλָ���½ڵ�
		q->_back = pNewNode;//backŲ���½ڵ�
	}
}

//������(ͷɾ)
void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;//pDelNode��ʾҪɾ���Ľ��
	if (QueueEmpty(q))//Ϊ��,���ܳ�����,ֱ�ӷ���
		return;

	pDelNode = q->_front;
	if (NULL == pDelNode->_pNext)//���Ҫɾ���Ľ�����һ�����Ϊ��.���Զ���ֻ��һ�����
	{
		q->_front = q->_back = NULL;
	}
	else
	{
		q->_front = pDelNode->_pNext;
	}

	free(pDelNode);
}

//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

//��ȡ��βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}

//��ǰ���е���ЧԪ������
int QueueSize(Queue* q)
{
	int count = 0;
	QNode* pCur = q->_front;//�Ӷ�ͷ��ʼ����
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

//�жϵ�ǰ�����Ƿ�Ϊ��
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_front;//�����ͷָ���,�����Ϊ��
}

//�ͷŶ��еĿռ�
void QueueDestroy(Queue* q)
{
	QNode* pCur = q->_front;
	while (pCur)//��ȷ�����в�Ϊ��
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}

	q->_front = q->_back = NULL;
}


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	QueueDestroy(&q);
}