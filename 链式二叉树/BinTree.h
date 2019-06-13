#pragma once


// ����������ʽ�洢��ʽ---���ӱ�ʾ��

typedef char BTDataType;
typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;


BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid);

// ����
BTNode* CopyBinTree(BTNode* pRoot);
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);
void LevelOrder(BTNode* pRoot);
int GetBinTreeSize(BTNode* pRoot);
int GetKLevelNodeCount(BTNode* pRoot, int K);
int GetLeafCount(BTNode* pRoot);
int GetBinTreeHeight(BTNode* pRoot);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void MirrorNor(BTNode* pRoot);
void Mirror(BTNode* pRoot);
void DestroyBinTree(BTNode** pRoot);

void TestBinTree();