#define _CRT_SECURE_NO_WARNINGS
//����һ��������n����1 - 1 / 3 + 1 / 5 - 1 / 7 + ......��n��֮�͡�
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	int denominator, flag, i, n;
//	double item, sum;
//
//	printf("Enter n:");
//	scanf("%d", &n);
//	flag = 1;
//	denominator = 1;
//	sum = 0;
//
//	for (i = 1; i <= n; i++)
//	{
//		item = flag*1.0 / denominator;
//		sum = sum + item;
//		flag = -flag;
//		denominator = denominator + 2;
//	}
//
//	printf("sum=%f\n", sum);
//	system("pause");
//	return 0;
//}

//����һ��������n��������n��ѧ���ĳɼ�������ƽ���֣���ͳ�Ʋ�����ɼ���ѧ��������
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int count, i, n;
//	double grade, total;
//
//	printf("Enter n:");
//	scanf("%d", &n);
//	total = 0;
//	count = 0;
//	for (i = 1; i <= n; i++){
//		printf("Enter grade#%d:", i);
//		scanf("%lf", &grade);
//		total = total + grade;
//		if (grade < 60){
//			count++;
//		}
//	}
//	printf("Grade average=%.2f\n", total / n);
//	printf("Number of failures=%d\n", count);
//	return 0;
//}

//���򵥵�����������ʽ������һ����ʽ�硰������  �����  ��������������������ʽ�����������
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	double value1, value2;
//	char op;
//	printf("Type in an expression:");
//	scanf("%lf%c%lf", &value1, &op, &value2);
//
//	if (op == '+')
//		printf("=%.2f\n", value1 + value2);
//	else if (op == '-')
//		printf("=%.2f\n", value1 - value2);
//	else if (op == '*')
//		printf("=%.2f\n", value1*value2);
//	else if (op == '/')
//		printf("=%.2f\n", value1 / value2);
//	else printf("Unknown operator\n");
//
//	return 0;
//}

//����10���ַ���ͳ������Ӣ����ĸ�������ַ��������ַ��ĸ���
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int digit, letter, other;
//	char ch;
//	int i;
//	digit = letter = other = 0;
//	printf("Enter 10 characters:");
//	for (i = 1; i <= 10; i++)
//	{
//		ch = getchar();
//		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
//			letter++;
//		else if (ch >= '0'&&ch <= '9')
//			digit++;
//		else other++;
//	}
//	printf("letter=%d,digit=%d,other=%d\n", letter, digit, other);
//	system("pause");
//	return 0;
//}


//���򵥱��ʽ������һ����ʽ�硰������  �����  ��������������������ʽ�������������Ҫ��ʹ��switch����д
#include <stdio.h>
#include <stdlib.h>

int main()
{
	double value1, value2;
	char op;
	printf("Type in an expression:");
	scanf("%lf%c%lf", &value1, &op, &value2);
	switch (op){
	case '+':
		printf("=%.2f\n", value1 + value2);
		break;
	case '-':
		printf("=%.2f\n", value1 - value2);
		break;
	case '*':
		printf("=%.2f\n", value1*value2);
		break;
	case '/':
		printf("=%.2f\n", value1 / value2);
		break;
	default:
		printf("Unknown operation\n");
		break;
	}

	return 0;
}
