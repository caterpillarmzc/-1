#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
public:
	Date(int year=2019,int month=7,int day=25)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date()" << endl;
	}

	~Date()
	{
		cout << "~Data()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
//new����ռ䲻��Ҫ�п�,����Ҫ����ת��
int main(){
	//new��mallocֻ��������ͷŵ����Ŀռ�
	//ʹ��new����ռ�
	Date* pd = new Date;
	delete pd;//�ͷ�

	//�������ʹ��malloc,���뵽����һ���С��Date��ͬ�Ŀռ�,���Ҳ��������Ĺ��캯��,������ֵ
	Date*pd2 = (Date*)malloc(sizeof(Date));
	free(pd2);
	//�������ռ�,ʹ��new[]��delete[]
	Date* pd3 = new Date[10];
	delete[] pd3;

	//new�����������͵Ŀռ�
	int *p1 = new int;
	int *p2 = new int(10);
	int *p3 = new int[10];//�����ռ�
	int *p4 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};//�����ռ䲢�ҳ�ʼ��

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}

