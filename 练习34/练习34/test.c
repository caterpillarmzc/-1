#define  _CRT_SECURE_NO_WARNINGS
//���1�� 2�� 3��n��n���˰�˳ʱ�뷽����һȦ��ÿ�������г���һ�����롣
//��ʼʱ��ѡһ����������Ϊ����������m���ӵ�һ���˿�ʼ��˳ʱ�뷽����1��ʼ˳�������
//����mֹͣ������m���˳��У��������е�������Ϊ�µı�������m��
//��˳ʱ�뷽���ϵ���һ����ʼ���´�1��������˱�����ȥ��
//�����ʣ�µ��Ǹ��˵��������Ƕ���
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int number;//���
	int psw;//��������
	struct node *next;
}LNode, *LinkLisk;

//������list��qָ����������һ���½��
void insertList(LinkLisk *list, LinkLisk q, int data1, int data2)
{
	LinkLisk p;
	p = (LinkLisk)malloc(sizeof(LNode));
	p->number = data1;
	p->psw = data2;
	if (!*list)
	{
		*list = p;
	}
	else
	{
		p->next = q->next;
		q->next = p;
	}
}

//����һ��Լɪ��
void creatJoseph(LinkLisk *jsp, int n)
{
	LinkLisk q = NULL, list = NULL;
	int i, elem;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		insertList(&list, q, i + 1, elem);//��qָ��Ľ�������µĽ��
		if (i == 0)
		{
			q = list;
		}
		else
		{
			q = q->next;
		}
	}
	q->next = list;//�γ�ѭ������
	*jsp = list;
}

//
void exJosph(LinkLisk *jsp, int m)
{
	LinkLisk p, q;
	int i;

	p = q = *jsp;
	while (q->next != p)
	{
		q = q->next;//qָ��p��ǰһ�����
	}
	while (p->next != p)
	{
		for (i = 0; i < m - 1; i++)
		{   //pָ��Ҫɾ���Ľ�㣬qָ��ɾ������ǰһ�����
			q = p;
			p = p->next;
		}
		q->next = p->next;//ɾ��pָ��Ľ��
		printf("%d ", p->number);//������е���
		m = p->psw;//���ñ�������
		free(p);//�ͷ�pָ��Ľ��
		p = q->next;//pָ��q�ĺ�һ�����
	}
	printf("\nThe last person in the cicrle is %d\n", p->number);
}

int main(void)
{
	LinkLisk jsp;
	int n, m;


	scanf("%d", &n);//����Լɪ������
	creatJoseph(&jsp, n);


	scanf("%d", &m);//����Լɪ�򻷱�������
	exJosph(&jsp, m);

	system("pause");
	return 0;
}


