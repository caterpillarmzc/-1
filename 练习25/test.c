//��1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
//#include<stdio.h>
//
//int main()
//{
//	int i, j, k;
//	printf("\n");
//	for (i = 1; i < 5; i++) { // ����Ϊ����ѭ��
//		for (j = 1; j < 5; j++) {
//			for (k = 1; k < 5; k++) { // ȷ��i��j��k��λ������ͬ
//				if (i != k&&i != j&&j != k) {
//					printf("%d,%d,%d\n", i, j, k);
//				}
//			}
//		}
//	}
//}

//��һ���������ֽ������������磺����90,��ӡ��90=2*3*3*5
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int n, i;
//	printf("������������");
//	scanf("%d", &n);
//	printf("%d=", n);
//	for (i = 2; i <= n; i++)
//	{
//		while (n%i == 0)
//		{
//			printf("%d", i);
//			n /= i;
//			if (n != 1) printf("*");
//		}
//	}
//
//	printf("\n");
//	return 0;
//}

//һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻�����£�
//�����ڵ�10�����ʱ�������������ף���10�η�����ߣ�
//#include<stdio.h>
//int main()
//{
//	float h, s;
//	h = s = 100;
//	h = h / 2; //��һ�η����߶�
//	for (int i = 2; i <= 10; i++)
//	{
//		s = s + 2 * h;
//		h = h / 2;
//	}
//	printf("��10�����ʱ��������%f�ף���10�η�����%f��\n", s, h);
//	return 0;
//}


//��ϰ��������
#include <stdio.h>
void hello_world(void)
{
	printf("Hello, world!\n");
}
void three_hellos(void)
{
	int counter;
	for (counter = 1; counter <= 3; counter++)
		hello_world();/*���ô˺���*/
}
int main(void)
{
	three_hellos();/*���ô˺���*/
}