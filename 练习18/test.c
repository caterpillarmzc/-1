#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <stdlib.h>
int main()
{
	//������W��ʽ���ļ�ʱ,������ļ���ԭ������
	/*FILE* fp = fopen("E:/test.txt","a");
	char str[] = "hahahahah";
	fwrite(str,1,strlen(str),fp);*/
	//read��write������ʾ���Ƕ�ȡ����д�������
	/*FILE* fp = fopen("E:/test.txt", "r");
	char buf[1024] = "haha";
	size_t n=fread(buf, 1, sizeof(buf), fp);
	printf("buf=%s\n",buf);
	printf("%d\n", n);
	fclose(fp);*/

	FILE* fp = fopen("E:/test.txt", "w");
	int x = 10;
	//���ַ�д�뵽txt��,
	//fprintf(fp,"x=%d", x);
	//���ַ��������Ļ��
	//fprintf(stdout,"x=%d\n", x);
	//sprintf����һ���ַ����������һ����ʽ���ַ���
	char buf[1024] = { 0 };
	sprintf(buf,"x=%d\n",x);
	//�������п���ʹ��sprintfʵ�ֽ�һ������(����,������)ת��Ϊһ���ַ���
	sprintf(buf, "%d", x);
	int y = 0;
	//sscanf�����෴
	sscanf(buf, "%d", &y);
	printf("y=%d\n", y);
	printf("%s\n", buf);
	fclose(fp);
	system("pause");
	return 0;
}