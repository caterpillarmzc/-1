//��һ���ַ�����ͷ���β����n���ո񣨡�   abcdefgdddd    ��������ȥ��ǰ��ո񣬷���һ�����ַ�����
//
//Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�70��
//
//Ҫ��2����д����������30��
//#include <stdio.h>
//#include <string.h>
//
////��ȥ��ǰ��Ŀո���ȥ������Ŀո�
//int trimSpace(char *inbuf, char *outbuf){
//	char *p = inbuf;
//	//�鿴�ж��ٸ��ո�
//	int len = 0;
//	while (p[len] == ' '){
//		len++;
//	}
//
//	//���ַ�������ǰ��
//	int i = len;
//	while (p[i]){
//		p[i - len] = p[i];
//		i++;
//	}
//	p[i - len] = '\0';
//
//	//ȥ��������ַ���
//	for (int j = 0; j < strlen(p); j++){
//		if (p[j] == ' '){
//			p[j] = '\0';
//			outbuf = p;
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//
//int main(){
//	char str[] = "        abcdefgdddd        ";
//	char *outbuf = NULL;
//
//	if (trimSpace(str, outbuf)){
//		printf("start.%s.end", str);
//	}
//	else{
//		printf("No need for trim.");
//	}
//
//}
//

//��һ���ַ�����1a2b3d4z��, ��
//
//Ҫ��дһ������ʵ�����¹��ܣ�
//
//����1����ż��λ�ַ���ѡ���������һ���ַ���1��valude��20��
//
//����2��������λ�ַ���ѡ���������һ���ַ���2��valude 20
//
//����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ��
//
//����4���������ܲ���ͨ����
#include <stdio.h>
#include <string.h>

//�����ַ��������������ȡ֮����ַ���
int getStr1Str2(char *str, char *buf1, char *buf2){
	char *p = str;
	int temp1 = 0;
	int temp2 = 0;

	if (p == NULL){
		return -1;
	}

	for (int i = 0; i < strlen(p); i++){
		if (i % 2 == 0){
			buf1[temp1] = p[i];
			temp1++;
		}
		else{
			buf2[temp2] = p[i];
			temp2++;
		}
	}

	return 1;
}

int main(){
	char str[] = "1a2b3d4z";
	char buf1[10] = { 0 };
	char buf2[10] = { 0 };

	if (getStr1Str2(str, buf1, buf2)){
		printf("buf1 = %s, buf2 = %s\n", buf1, buf2);
	}
	else{
		printf("Error!");
	}
}
