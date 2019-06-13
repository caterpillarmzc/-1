#include "BinTree.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "Queue.h"



BTNode* BuyBinTeeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}

// �������Ĵ��� 
BTNode* _CreateBinTree(BTDataType* array, int size, int* index, BTDataType invalid)
{
	BTNode* pRoot = NULL;
	if (*index < size && invalid != array[*index])
	{
		// ���ڵ�
		pRoot = BuyBinTeeNode(array[*index]);

		// ����������
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);

		// ����������
		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}

	return pRoot;
}

// �ݹ飺������� 
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// �ݹ飺�������
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// �ݹ飺�������
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

// �������
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		printf("%c ", pCur->_data);

		// ������Ӵ��ڣ����浱ǰ�ڵ������
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		// ����Һ��Ӵ��ڣ����浱ǰ�ڵ���Һ���
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}

	QueueDestroy(&q);
	printf("\n");
}

//�����ڵ�
void Swap(BTNode** pLeft, BTNode** pRight)
{
	BTNode* pTemp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTemp;
}

void MirrorNor(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		Swap(&pCur->_pLeft, &pCur->_pRight);

		// ������Ӵ��ڣ����浱ǰ�ڵ������
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		// ����Һ��Ӵ��ڣ����浱ǰ�ڵ���Һ���
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}

	QueueDestroy(&q);
}

// �������ľ���
void Mirror(BTNode* pRoot)
{
	if (pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}

BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}

//ȷ��Ҷ�ӽ�����
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (NULL == pRoot || K <= 0)
		return 0;

	if (1 == K)
		return 1;

	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) +
		GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

BTNode* BinaryTreeFind(BTNode* pRoot, BTDataType x)
{
	BTNode* pRet = NULL;
	if (NULL == pRoot)
		return NULL;

	if (x == pRoot->_data)
		return pRoot;

	if (pRet = BinaryTreeFind(pRoot->_pLeft, x))
		return pRet;

	return BinaryTreeFind(pRoot->_pRight, x);
}

//���ٶ�����
void DestroyBinTree(BTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void TestBinTree()
{
	char* str = "ABD$$$CE$$F";
	BTNode* pRoot = CreateBinTree(str, strlen(str), '$');
	Mirror(pRoot);
	MirrorNor(pRoot);
	printf("ǰ����������");
	PreOrder(pRoot);
	printf("\n");

	printf("������������");
	InOrder(pRoot);
	printf("\n");

	printf("������������");
	PostOrder(pRoot);
	printf("\n");

	printf("������������");
	LevelOrder(pRoot);

	printf("K=3: %d\n", GetKLevelNodeCount(pRoot, 3));

	if (BinaryTreeFind(pRoot, 'E'))
	{
		printf("E is in BTree!!!\n");
	}
	else
	{
		printf("E is not in BTree!!!\n");
	}
	DestroyBinTree(&pRoot);
}