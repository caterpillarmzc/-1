//�ֱ���while��forдһ�����򡣳������û�����һ��n��Ȼ�����1��n�ĺ͡�
//#include<stdio.h>
//int main()
//{
//	int n;
//	int sum = 0, i = 1;
//	scanf("%d", &n);
//	while (i <= n)
//	{
//		sum += i;
//		i++;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int n;
//	int sum = 0, i;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//
//��дһ�����򣬳���ʵ���û��������������������ǵ���С�����������Լ��
//
//
//#include<stdio.h>
//
//int main()
//{
//	int n, m, temp, sum;
//	scanf("%d%d", &n, &m);
//	sum = n*m;
//	if (n < m)
//	{
//		temp = n;
//		n = m;
//		m = temp;
//	}
//	while (n%m != 0)
//	{
//		temp = m;
//		m = n%m;
//		n = temp;
//	}
//	printf("���Լ����%d\n", m);
//	printf("��С��������%d\n", sum / m);//��С�����������������ĳ˻��������Լ�� 
//	return 0;
//}