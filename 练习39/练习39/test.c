//��дһ��������ʵ��˳���ľ͵����ã�Ҳ����˵����ԭ��Ĵ洢�ռ佫˳���a1,a2��an��,����Ϊ��an,an-1��a1)
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10//��̬˳�������ռ�

typedef struct
{
	int *base;
	int length;
}Sqlist;//˳���


void reverseSQ(Sqlist *l)
{   //ʵ��˳���l�ľ͵�����
	int low = 0, high = l->length - 1;
	int buf, i;


	for (int i = 0; i < l->length / 2; i++)
	{   //ѭ��l->length/2��
		buf = l->base[low];
		l->base[low] = l->base[high];
		l->base[high] = buf;
		low++;
		high--;
	}
}
int main(int argc, char const *argv[])
{
	Sqlist l;
	int i, data;

	l.base = (int*)malloc(sizeof(int)* MAXSIZE);
	l.length = 0;//����˳���
	if (!l.base)
	{   //�����ڴ�ʧ��
		printf("error!\n");
	}

	//��������

	for (i = 0; i < MAXSIZE; i++)
	{
		scanf("%d", &l.base[i]);
		l.length++;
	}

	//�������

	for (i = 0; i < l.length; i++)
	{
		printf("%d ", l.base[i]);
	}
	printf("\n");

	reverseSQ(&l);//�͵�����

	for (i = 0; i < l.length; i++)
	{
		printf("%d ", l.base[i]);
	}

	system("pause");
	return 0;
}

//�Ӽ����������������������0��Ϊ������־��������������д�С�������򣬲���������Ľṹ
#include <stdio.h>
#include <stdlib.h>

//��������Ľ������
typedef struct node
{
	int data;
	struct node *next;
}LNode, *LinkList;

//����һ������Ϊn������
LinkList creatList(int n)
{
	LinkList p, q, list = NULL;
	int elem, i;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		p = (LinkList)malloc(sizeof(LNode));
		if (!p)
		{
			return NULL;
		}
		p->data = elem;
		p->next = NULL;
		if (list == NULL)
		{
			list = p;//��һ�����
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
	return list;
}

//�������в����㣬����ý����������д������
void insertList(LinkList *list, LinkList q, int elem)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	if (!p)
	{
		return;
	}
	p->data = elem;
	if (!*list)
	{   //����׽��Ϊ��
		*list = p;
		p->next == NULL;
	}
	else
	{   //������
		p->next = q->next;
		q->next = p;
	}
}

//��������ð������
void bubbleSort(LinkList list)
{
	LinkList p = list;
	int temp, i, j, k = 0;

	while (p)
	{
		k++;
		p = p->next;
	}//kΪ����Ԫ�ظ���

	p = list;
	for (i = 0; i < k - 1; i++)
	{
		for (j = 0; j < k - 1 - i; j++)
		{
			if (p->data > p->next->data)
			{   //����һ��λ�ý��бȽ�
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		p = list;//ָ������ָ��ͷ
	}
}

//��ӡ��������������
void print(LinkList list)
{
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

int main(int argc, char const *argv[])
{
	LinkList q, r;
	int elem;

	q = r = creatList(1);//����һ�������㣬q��r��ָ��������

	scanf("%d", &elem);
	while (elem)
	{   //ѭ����������ͬʱ������
		insertList(&q, r, elem);
		r = r->next;
		scanf("%d", &elem);
	}

	bubbleSort(q);
	print(q);

	system("pause");
	return 0;
}

//��������Ԫ��ֵ�������������е�����list1��list2������Ҫ�����������
//��һ����Ԫ��ֵ��������������list3��Ҫ������ԭ��ռ�Ľ��ռ乹���±�
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LNode, *LinkList;

//����һ������Ϊn������
LinkList creatLinkList(int n)
{
	LinkList p, r, list = NULL;
	int elem, i;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		p = (LinkList)malloc(sizeof(LNode));
		if (!p)
		{
			return NULL;
		}
		p->data = elem;
		p->next = NULL;
		if (!list)
		{
			list = p;
		}
		else
		{
			r->next = p;
		}
	}
	return list;
}

//�������в����㣬����ý����������д������
void insertList(LinkList *list, LinkList q, int elem)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = elem;
	if (!p)
	{
		return;
	}
	if (!*list)
	{
		*list = p;
		p = p->next;
	}
	else
	{
		p->next = q->next;
		q->next = p;
	}
}

//��pָ��Ľ����뵽q1,q2��ָ��Ľ�㵱��
void insertNode(LinkList *q1, LinkList *q2, LinkList *p, LinkList *l2)
{
	if (*q1 == *q2)
	{   //l1�����һ���������С����l2�����һ��������ݣ�����
		(*p)->next = *q2;
		*l2 = *q2 = *q1 = *p;
	}
	else
	{
		(*q2)->next = *p;
		(*p)->next = *q1;
		(*q2) = (*q2)->next;
	}
}

//��l1,l2ԭ�ռ�����鲢����l3����
void mergeLink(LinkList l1, LinkList l2, LinkList *l3)
{
	LinkList p, q1, q2;
	q1 = q2 = l2;//q1, q2ָ��l2����
	p = l1;//pָ��l1����
	while (p && q1)
	{
		if (p->data >= q1->data)
		{
			q2 = q1;
			q1 = q1->next;
		}
		else
		{
			l1 = l1->next;
			insertNode(&q1, &q2, &p, &l2);
			p = l1;
		}
		/*
		pָ��l1����q1,q2ָ��l2����q2ʼ����q1��һ��λ��
		�Ƚ�p->data �� q1->data ,
		1.���p->data >= q1->data, q1,q2ָ������һ��λ��
		2.���p->data < q1->data, ��p����q1,q2֮��
		ֱ��ĳһ����Ϊ�ս���
		*/
	}
	if (!q1)
	{
		q2->next = p;
	}
	/*
	���l1����Ϊ�գ���ôl1�Ѿ���ȫ����ϲ���l2��
	���l2����Ϊ�գ���l2βָ��ָ��l1����
	*/
	*l3 = l2;//l2�׽�㸳��l3
}

//��ӡ����
void print(LinkList list)
{
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

int main(void)
{
	LinkList l1, l2, l3, q;
	int elem;

	//��������l1
	q = l1 = creatLinkList(1);
	scanf("%d", &elem);
	while (elem)
	{
		insertList(&l1, q, elem);
		q = q->next;
		scanf("%d", &elem);
	}

	//��������l2
	q = l2 = creatLinkList(1);
	scanf("%d", &elem);
	while (elem)
	{
		insertList(&l2, q, elem);
		q = q->next;
		scanf("%d", &elem);
	}

	//�鲢����
	mergeLink(l1, l2, &l3);
	//��ӡ�ϲ�����
	print(l3);

	system("pause");
	return 0;
}
