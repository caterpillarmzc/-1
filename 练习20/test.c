//
////һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
////�ҳ����������֣����ʵ�֡�
////˼·:�������е�����ͷ��β������򣬳���ż���ε������Ϊ0��
////���ս��������ֻ����һ�ε��������Ľ�����������������ֲ�ͬ��
////���Ľ��һ����Ϊ0����������Ʊ�ʾ��ʽ��һ������ĳһλΪ1��
////�ҵ���һ��Ϊ1��λ�������ǵ�Nλ����ô�ڶ�Ӧ����һλ�ϣ�
////��������һ��Ϊ0��һ��Ϊ1�����ݵ�Nλ�Ƿ�Ϊ1����ԭ����ֳ����������飬
////��������������ж�ֻ����һ��ֻ������һ�ε������������������������Σ�
////�����������е�Ԫ�طֱ���򣬾͵õ�������ֻ����һ�ε���
//#include <stdio.h>
//void search(int arr[], int len)
//{
//	int ret = 0;
//	int n = 0;
//	int num1 = 0;
//	int num2 = 0;
//	for (int i = 0; i < len; i++)
//	{
//		ret ^= arr[i];
//	}
//	//��ret���ұߵ�1
//	n = ret - (ret&(ret - 1));
//	for (int i = 0; i < len; i++)
//	{//ȡ��arr[i]�ĵ�nλ
//		int a = (arr[i] >> (n - 1)) % 2;   
//		if (a == 0)
//		{
//			num1 ^= arr[i];
//		}
//		else
//		{
//			num2^= arr[i];
//		}
//	}
//	printf("%d, %d\n", num1, num2);
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 6, 6, 1, 3, 5, 2, 8, 7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	search(arr, len);
//
//	system("pause");
//	return 0;
//}

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ�����ʵ�֡�
//#include <stdio.h>
//int num(int n)
//{
//	int count = n;
//	while (n>1)
//	{
//		count = count + n / 2;
//		n = n / 2 + n % 2;
//	}
//	return count;
//}
//int main()
//{
//	int n = 20;
//	int ret = num(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}


//ģ��ʵ��strcpy 
//char* Strcpy(char* dest,const char* src)
//{
//	int i = 0;
//	//��src�ĵ�0��Ԫ�ؿ�ʼһ��һ��ȡԪ��,
//	for (; src[i] != '\0'; ++i)
//	{
//		dest[i] = src[i];
//	}
//	dest[i] = '\0';
//}
//#include <stdio.h>
//int main()
//{
//	char*p = "abcdef";
//	char str[1024] = { 0 };
//	Strcpy(str, p);
//	printf("%s\n", str);
//	system("pause");
//}

//ʵ��strcat
#include <string.h>
#include <stdio.h>
char* Strcat(char* dest,const char* src)
{
	//����dest���ҵ�\0
	int i = 0;
	//ѭ��������,i��Ӧ��Ԫ�ؾ���\0
	for (; dest[i] != '\0'; ++i);
	//�ٰ�src�е��ַ�һ�θ�ֵ��ȥ
	int j = 0;
	for (; src[j] != '\0'; ++i, ++j);
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	char str1[1024] = "aaa";
	char str2[1024] = "bbb";
	Strcat(str1, str2);
	printf("%s\n", str1);
	printf("%s\n", str2);

	system("pause");
	return 0;
}