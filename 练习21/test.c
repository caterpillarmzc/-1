//��ϰ��̬�ڴ������
//malloc
//#include <stdio.h>
//#include<stdlib.h>
//
//int main(){
//	//malloc()�б�ʾ���������ڴ�ռ�Ĵ�С
//	int *p = (int*)malloc(10 * sizeof(int));
//	for (int i = 0; i < 10;++i )
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10;++i )
//	{
//		printf("%d\n", p[i]);
//	}
//	//�ڴ��ͷ�,���ͷŵĻ�������������
//	//���һֱ���뵫���ͷ�,�������ڴ�й©
//	//��������������벻����
//	free(p);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//����alloc����Ķ�̬�ڴ治����free
//	//һ������Ķ�̬�ڴ治���ͷ�����
//	int num = 10;
//	int*p = &num;
//	free(p);
//	//�ͷź�õ���ָ����Ұָ��
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
////calloc��ϰ
//int main(){
//	
//	int *p = (int*)calloc (10,sizeof(int));
//	for (int i = 0; i < 10; ++i)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d\n", p[i]);
//	}
//	
//	free(p);
//	system("pause");
//	return 0;
//}

//#include <stdio.h> #include <stdlib.h>
//
//int main() {
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)    {        //ʹ�ÿռ� 
//	}    
//	free(p);
//	p = NULL;
//	system("pause");
//	return 0;
//}

//#include <stdlib.h>
//#include<stdio.h>
//
//int main()
//{
//	char* p = (char *)malloc(100);
//	if (p)
//		printf("�ڴ������: %p\n", p);
//	else
//		printf("û���㹻�ڴ�!/n");
//	char *lcf = (char *)realloc(p, 256);
//	if (lcf)
//		printf("�ڴ����·�����: %p\n", lcf);
//	else
//		printf("û���㹻�ڴ�!/n");
//	free(lcf);
//	system("pause");
//	return 0;
//}
