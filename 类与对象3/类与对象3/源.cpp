#include <iostream>
using namespace std;
/*
��ʼ���б������:
��ʼ�����еĳ�Ա����
ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)
�����ʼ���б�û����ʾ����,���������Զ���ɳ�ʼ���б�Ĺ���,�����ֵ
���Ǻ������п��Ը�ֵ���
���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ���� 
���ó�Ա���� 
const��Ա���� 
�����ͳ�Ա(����û��Ĭ�Ϲ��캯��)
*/
#if 0
//ʱ����Ĺ��캯��:��ȱʡֵ�Ĺ��캯��
class Time
{
public:
	Time(int hour,int minute,int second)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{

	}
protected:
private:
	int _hour;
	int _minute;
	int _second;
};
//���������а���һ��ʱ����Ķ���
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
		,_a(year)//�������͵ĳ�Ա������ʼ��
		,_c(year)//const��Ա������ʼ��
		,_t(0,0,0)//�������ͳ�Ա��ʼ��
	{}
private:
	int _year;
	int _month;
	int _day;
	int & _a;
	const int _c;
	Time _t;

};

#endif
#if 0
//����ʹ�ó�ʼ���б���г�ʼ��,��Ϊ�������Ƿ�ʹ�ó�ʼ���б�,�����Զ������͵ĳ�Ա����,һ����ʹ�ó�ʼ���б��ʼ��

class A
{
public:
	A(int a = 10)
		: _a(a)
	{
		cout << "A::A()" << endl;
	}
private:
	int _a;
};

class B
{
public:
	B()
		//: _a(10)    ��ʹû�и���,������Ҳ���Զ�����ⲽ����
	{

	}

private:
	A _a;
};

int main(){
	B b;
	return 0;
}
#endif
class Date
{
public://��������
	Date(int year, int month)
		:_year(year)
		, _day(month)
		,_month(_day)
	{}
private://��ʼ������
	int _year;
	int _day;
	int _month;
	/*int _year;����д��month���ܳ�ʼ���ɹ�,
	int _month;��Ա�����ڹ��캯����ʼ������:���ճ�Ա�������������Ⱥ���������г�ʼ��
	int _day;  �����ǰ����ڳ�ʼ���б��г��ֵ��Ⱥ����*/
};//������Ҫʹ�ó�Ա����ʼ����Ա,��ð���������������ʼ����Ա

int main(){
	Date d(2019, 7);
	return 0;
}