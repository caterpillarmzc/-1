//һԪһƿ��ˮ�������������ƿ�ӻ�һƿ��ˮ���ʣ���20��Ǯ�������Ժȶ���ƿˮ��
#include <stdio.h>
int money(double money, int sum)
{
	while (money >= 1)
	{
		sum = sum + (int)money;
		money = ((int)money) * 0.5 + money - (int)money;
		printf("money = %f\n", money);
	}
	return sum;
}
void main()
{
	int sum = 0;
	sum = money(20.0, 0);
	printf("%d\n", sum);
}


/*һ��������������������ƽ��ֵ(ʹ�ÿɱ�����б�)
�ɱ�����б����ã����Դ��������Ĳ�����
�ɱ�����б�ʵ�ַ������ɱ�����б���ͨ������ʵ�ֵģ���Щ�궨����stdarg.hͷ�ļ��У����Ǳ�׼���һ���֡�
���ͷ�ļ�����һ������va_list ��������va_start��va_arg��va_end��
���ǿ�������һ������Ϊva_list�ı��������⼸�������ʹ�ã����ʲ�����
�������������ã�
����һ��va_list ���͵ı���arg�������ڷ��ʲ����б��δȷ�����֣���������ǵ���va_start����ʼ���ģ�
���ĵ�һ��������va_list�ı���������2��������ʡ�Ժ�ǰ���һ�������ֵĲ�����
��ʼ�����̰�arg��������Ϊָ��ɱ�������ֵĵ�һ��������
Ϊ�˷��ʲ�������Ҫʹ��va_arg��������������������va_list�����Ͳ����б�����һ�����������͡�
va_arg�������������ֵ����ʹ��va_argָ����һ���ɱ������
��󣬵�����������һ���ɱ����֮��������Ҫ����va_end*/
#include<stdio.h>
#include<stdarg.h>

int average(int val, ...)
{
	va_list arg;
	int count = 0;
	int sum = 0;

	va_start(arg, val);
	for (count = 0; count < val; count++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg);

	return sum / val;
}
int main()
{
	int ret = average(3, 2, 4, 6);
	printf("ƽ����Ϊ��%d\n", ret);
	return 0;
}

//��һ���ַ����� student a am i, �ֽ��ַ���ת��Ϊ i am a student �ռ临�Ӷ�Ϊ : O(1)


#include<stdio.h>
#include<assert.h>
void my_reverse(char* left, char* right)
{
	assert(left);
	assert(right);

	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int my_strlen(char *str)//�õ����鳤�ȶ�����ȡ�ַ������ȵĺ���
{
	assert(str);
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

void Reverse(char s[])
{
	assert(s);
	char* start = s;
	char* end = s + my_strlen(s) - 1;
	char* cur = NULL;

	my_reverse(start, end);

	while (*s)
	{
		cur = s;
		while (*s != '\0' && *s != ' ')
		{
			s++;
		}
		end = s - 1;
		my_reverse(cur, end);
		if (*s == ' ')
		{
			s++;
		}
	}
}

int main()
{
	char s[] = "student a am i";
	Reverse(s);
	printf("%s\n", s);
	return 0;
}


//�ٶȱ�����  ʹ��c���Ա�д���� unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����ģʽ�����ҷ�ת���ֵ
//00000000000000000000000000011001  ��תǰ  25
//10011000000000000000000000000000  ��ת��
//���������أ� 2550136832
#include<stdio.h>

int reverse_bit(unsigned int value)
{
	int ret = 0;
	int bit = 0;
	for (int i = 0; i < 32; i++)
	{
		ret = ret << 1;		//����һλ������ǰһλ  
		bit = value & 1;	//ȡ�����һλ  
		value = value >> 1;	//ֵ���ƣ�ȡ��һλ  
		ret = bit | ret;	//���һλ����ret  
	}
	return ret;
}

int main()
{
	unsigned int value = 25;
	unsigned int ret = reverse_bit(value);
	printf("%u\n", ret);
	return 0;
}
