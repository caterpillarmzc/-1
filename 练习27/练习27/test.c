
#define _CRT_SECURE_NO_WARNINGS
//��һ�����У�8,4,2,1,23,344,12����ѭ��������е�ֵ����������������ֵ�ĺͼ�ƽ��ֵ��������Ϸ��
//���Ӽ�������������һ�����ݣ��ж��������Ƿ����������

#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int i; //ѭ������
//	int sum = 0;
//	int searchNum;    //Ҫ���ҵ�����
//	double avg;
//	//�������飬����ʼ��
//	int nums[] = { 8, 4, 2, 1, 23, 344, 12 };
//	//ѭ�����
//	printf("�������Ԫ�أ�\n");
//	for (i = 0; i < 7; i++)
//	{
//		printf("%d\t", nums[i]);
//	}
//	printf("\n*****************************\n");
//	//��ͼ�ƽ��ֵ
//	for (i = 0; i < 7; i++)
//	{
//		sum += nums[i];  //�����ۼ�
//	}
//	avg = sum / 7.0;
//	printf("����%d��ƽ��ֵΪ%lf", sum, avg);
//	printf("\n*****************************\n");
//	//��������
//	printf("������Ҫ���ҵ����֣�");
//	scanf("%d", &searchNum);
//	for (i = 0; i < 7; i++)
//	{
//		//һ��һ��Ԫ�ؽ��жԱ�
//		if (searchNum == nums[i])
//		{
//			printf("�ҵ�����ͬ��Ԫ�أ�\n");
//			break;
//		}
//	}
//	
//	//ͨ���۲죬ѭ�������˳�ʱ��i��ֵӦ��Ϊ7
//	if (i == 7){
//		printf("û���ҵ����ʵ����֣�");
//	}
//	return 0;
//}

//ѭ��¼��5���������֣����н������к�������

//#define N 5  //�궨�壬�����Ǳ����
//
//int main()
//{
//	int i, j;  //ѭ������
//	int temp;  //������������ʱ����
//	int nums[N] = { 16, 25, 9, 90, 23 };
//	//���ѭ����������
//	for (i = 0; i < N - 1; i++)
//	{
//		//�ڲ�ѭ������ÿ�ֵıȽϴ���
//		for (j = 0; j < N - i - 1; j++)
//		{
//			//�����ǰֵС�ں���һ��ֵ���ͽ���
//			if (nums[j] < nums[j + 1])
//			{
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//	printf("�����Ľ���ǣ�\n");
//	for (i = 0; i < N; i++)
//	{
//		printf("%d\t", nums[i]);
//	}
//	return 0;
//}

//����Ҫ��������а�ս����ս��ֵ�Ӵ�С���У�
//ɾ��ս����42322������ս����41000�����ֽ���

int main()
{
	int count = 5; //��ʾ����Ԫ�صĸ���
	double powers[5] = { 42322, 45771, 40907, 41234, 40767 };
	double deletePower;   //�û�Ҫɾ����ս��ֵ
	int deleteIndex = -1;   //Ҫɾ��ս��ֵ���±꣬��һ�������ܵ�ֵ�������ж�
	int i;             //ѭ������
	double insertPower;   //�²����ս��ֵ
	printf("������Ҫɾ����ս��ֵ��");
	scanf("%lf", &deletePower);
	for (i = 0; i < count; i++)
	{
		if (deletePower == powers[i])
		{
			//��¼�µ�ǰ���±�
			deleteIndex = i;
			break;  //�ҵ���Ҫɾ����ս��ֵ��ֱ������ѭ��������Ч��
		}
	}
	//�����ж�(�Ƿ��ҵ�)��ִ�к����Ĳ���
	if (-1 == deleteIndex)
	{
		printf("û���ҵ�Ҫɾ����ս��ֵ\n");
	}
	else
	{
		//���±꿪ʼ������һ������ǰ��һ������
		for (i = deleteIndex; i < count - 1; i++)
		{
			powers[i] = powers[i + 1];
		}
		//ɾ����һ���ǵ�������ܳ���-1
		count--;
	}
	printf("ɾ����Ľ��Ϊ��\n");
	for (i = 0; i < count; i++)
	{
		printf("%.2lf\t", powers[i]);
	}
	//ɾ��֮����в���
	printf("\n�������µ�ս��ֵ��");
	scanf("%lf", &insertPower);
	powers[count] = insertPower;
	//���������Ϻ󣬼ǵ��ܳ��ȼ�1
	count++;
	printf("�����Ľ��Ϊ��\n");
	for (i = 0; i < count; i++)
	{
		printf("%.2lf\t", powers[i]);
	}
	return 0;
}