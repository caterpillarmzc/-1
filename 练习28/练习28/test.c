//��#define������ϰ��
//#include<stdio.h>
//#define TRUE 1
//#define FALSE 0
//#define SQ(x) (x)*(x)
//int main()
//{
//	int num;
//	int again = 1;
//	printf("���ֵС�� 50 ������ֹ��\n");
//	while (again)
//	{
//		printf("\n���������֣�");
//		scanf("%d", &num);
//		printf("�����ֵ�ƽ��Ϊ %d \n", SQ(num));
//		if (num >= 50)
//			again = TRUE;
//		else
//			again = FALSE;
//	}
//	return 0;
//}


//��#define������ϰ2��
//#include<stdio.h>
//#define exchange(a,b) { int t;t=a;a=b;b=t;}//ע�����һ����
//int main()
//{
//	int x = 10;
//	int y = 20;
//	printf("x=%d; y=%d\n", x, y);
//	exchange(x, y);
//	printf("x=%d; y=%d\n", x, y);
//	return 0;
//}
//��#define������ϰ3��
#define LAG >
#define SMA <
#define EQ ==
#include <stdio.h>
int main()
{
	int i, j;
	printf("�������������֣�\n");
	scanf("%d %d", &i, &j);
	if (i LAG j)
		printf("%d ���� %d \n", i, j);
	else if (i EQ j)
		printf("%d ���� %d \n", i, j);
	else if (i SMA j)
		printf("%d С�� %d \n", i, j);
	else
		printf("û��ֵ��\n");
	return 0;
}