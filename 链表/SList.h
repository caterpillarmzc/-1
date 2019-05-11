#pragma once
#include <stdlib.h>
//����Ľڵ�
typedef struct Node
{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ,�ҵ����һ��ΪNULLʱ����
}Node;

//��ʼ���������һ��������,һ���ڵ㶼û�е�����,��first=NULL
void SListInit(Node **){
	*ppFirst = NULL;
}

void SListPushFront(Node **ppFirst, int v){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = *ppFirst;
	*ppFirst = node;

}

//ͷ��
void Test(){
	Node *first;
	SListInit(&first);

	SListPushFront(&first, 1);
	//1->NULL
	SListPushFront(&first, 1);
	//2->1->NULL
	SListPushFront(&first, 1);
	//3->2->1->NULL
	SListPushFront(&first, 1);
	//4->3->2->1->NULL
}

//ͷɾ
void SListPopFront(Node **ppFirst){
	assert(*ppFirst != NULL);//һ����㶼û�еĻ�,�޷�����ɾ��
	Node *next = (*ppFirst)->next;//��һ���ط����1�ĵ�ַ,��ֹ�ͷŶ�ʧ
	free(*ppFirst);
	*ppFirst = next;
}

//β��
void SListPushBack(Node **ppfirst,int v){
	//�����¿ռ�
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;//node���µ����һ�����,����next=NULL
	if (*ppfirst==NULL){
		*ppfirst = node;
		//����Ϊ��,û���κν��
		*ppfirst = node;	
	}
	else
	{
	//�����һ�����,���һ������nextһ����NULL
	Node *cur = *ppfirst;
	while(cur->next!=NULL){
		cur = cur->next;
	}
	//cur�������һ�����
	Node *node = (Node*)malloc(sizeof(Node));
	node ->value = v;
	node->next = NULL;
	//��ԭ�����һ������next=�µĽڵ�
	cur ->next = node;

	}
}

//βɾ
void SListPopBack(Node **ppFirst){
	//��������ʱ,�޷�����βɾ����,�˳�
	assert(*ppFirst != NULL);
	//������ֻ��һ�����ʱ�����
	if ((*ppFirst)->next==NULL){
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}
	//������Ľ��������1ʱ�����
	//�ҵ������ڶ������
	//��Ϊcur->next->next == NULL
	Node *cur = *ppFirst;
	while (cur->next->next==NULL){
		cur = cur->next;
	}
	//�ͷ����һ�����
	free(cur->next);
	cur->next = NULL;
}

//����
Node * SListFind(const Node *first,int v){
	for (Node*cur = first; cur != NULL;cur=cur->next){
		if (cur->value==v){
			return cur;
		}
	}
	return NULL;
}

//�ͷ�
void SListDestroy(Node *first){
	Node *next;
	for (Node *cur = first; cur != NULL;cur=next){
		next = cur->next;
		free(cur);
	}
}

//posһ���������еĽ��
//��ָ��λ��pos����������
void SListInsertAfter(Node *pos,int v){
	Node *node = (Node*)mallloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//posһ���������еĽ��
//��ָ��λ��pos������ɾ��
void SListEraseAfter(Node *pos){
	Node *next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

