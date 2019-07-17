#include <stdio.h>
#include <iostream>
using namespace std;

#if 0
//���캯��
class Date
{
public:
	//���ι��캯��
	Date(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
#if 0
	//�޲ι��캯��
	Date(){

	}
	//ȫȱʡ���캯��,����һ����ʼֵ
	Date(int year = 2019, int month = 7, int day = 16){
		_year = year;
		_month = month;
		_day = day;
	}
#endif
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate(){
	Date d1(2019, 7, 16);//�����вι��캯��
	Date d2();//�����޲ι��캯��
	d1.PrintDate();

}
/*�������û����ʽ���幹�캯��,����������Զ�����һ���޲ε�Ĭ�Ϲ��캯��,
���û�����,��������
�޲ι��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��,����ֻ�ܴ���һ��
һ����ȫȱʡ
ע��:�޲ι��캯��,ȫȱʡ���캯��,�������Զ����ɵĹ��캯����������Ϊ��Ĭ�ϳ�Ա����

*/
int main(){
	TestDate();
}

/*
���캯����һ������ĳ�Ա����,������������ͬ,���������Ͷ���ʱ�ɱ�����
�Զ�����,��֤ÿ�����ݳ�Ա����һ�����ʵĳ�ʼֵ,�����ڶ�������������ֻ����һ��
���캯��û�з���ֵ����,���ü�void
һ������,���캯�������ж��,���������ͬ,���캯����ͬ
���캯����Ҫ�������ڿռ��д�������,���ǳ�ʼ������
���캯��������:
1.��������������ͬ
2.�޷���ֵ
3.����ʵ����ʱ�������Զ����ö�Ӧ�Ĺ��캯��
4.���캯����������
*/
#endif

#if 0
class Date
{
public:
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) //ð��֮���ǳ�ʼ�������б�
		: _year(year)
		, _month(month)
		, _day(day)
	{
		// һ�����뵽���캯�����У������Ѿ������ɹ�
		// ���е��Ǹ�ֵ�����ǳ�ʼ��,������Ͳ���д����������,����д��������
		//_year = year;
		//_month = month;
		//_day = day;

	}
	//�������캯��ͬ��
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 6, 16);
	Date d2(d1);
	return 0;
}
#endif

#if 0
//��������

#include <assert.h>
#include <malloc.h>
typedef int DataType;

class SeqList{
public:
	SeqList(size_t capacity=3){
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr==_array)
		{
			assert(0);
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
		//��������
	~SeqList(){
			if (_array)
			{
				free(_array);
				_array = nullptr;
			}
		}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void TestSeqlist(){
	SeqList s;
}
/*
��������������ɶ��������,�������ɱ�������ɵ�,�����ڶ�������ʱ
�Զ�������������,������һЩ��Դ������
(���ϵĿռ���Ҫ�����������ͷ�)
��������������:
1.����������������ǰ����ȡ������~
2.�޲����޷���ֵ��������
3.һ��������ֻ��һ����������,δ��ʽ������������Զ�����Ĭ�ϵĵ���������
4.�����������ڽ���ʱ,C++����ϵͳ�Զ�������������
5.���������ɵ�Ĭ����������,����Զ����ͳ�Ա����������������
*/
int main(){
	TestSeqlist();
	return 0;
}


#endif

#if 0


//�������캯��
class Date{
public:
	//ȫȱʡ�Ĺ��캯��
	Date(int year=2019,int month=7,int day=16){
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintData(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate(){
	Date d1;
	//Date d2(2019,7,16);
	Date d3(d1);//ʹ��d2��������d3
}
int main(){
	TestDate();
	return 0;
}
/*
�������캯��:
ֻ�е����β�,���β��ǶԱ������Ͷ��������(����const����)
��const���ε�Ŀ���Ǹ����ڼ䲻�ı�ԭ��������
�����Ѵ��ڵ������Ͷ��󴴽��¶���ʱ�ɱ������Զ�����
�������캯��������:
1.�������캯���ǹ��캯����������ʽ(ͬһ������,������ͬ,�����б�ͬ)
2.�������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô���(����Date&d����Date d3(d2)��d2����d3),
  ʹ�ô�ֵ��ʽ����������ݹ����
3.��δ��ʽ����,��ϵͳ����Ĭ�ϵĿ������캯��,Ĭ�ϵĿ������캯��
�������ڴ�洢���ֽ�����ɿ���,���ֿ������ǳ�֮Ϊǳ��������ֵ����
ǳ�������¶��������һ����Դ,����ͷŻᵼ�³������
*/
#endif


#if 0
//�����������
class Date{
public:
	//ȫȱʡ�Ĺ��캯��,����һ����ʼֵ
	Date(int year = 2019, int month = 7, int day = 16){
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintData(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
	//���������
	Date operator+(int days){//ע�����������Date&,,��ʾ����ֵ������ջ�ϵĿռ�,��tmp����ջ�ϵĿռ�,����������,tmp�ͻᱻ����
		Date tmp(*this);//����һ����ʱ��������֤+֮��ԭ����day����
		tmp._day += days;
		return tmp;
	}
	//������䵱��ȫ�ֺ���ʱ,��Ҫ��������d1��d2,���������ж���ʱ,thisָ��Ҳ��һ������
	bool operator ==(const Date &d){
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
	bool operator !=(const Date &d){
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
#if 0
	//����
	bool operator ==(const Date &d){
		return !(*this == d);
	}
#endif
	// ǰ��++
	Date& operator++()
	{
		_day += 1;
		return *this;//����+1֮����µ�ֵ
	}

	// ����++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;//����+1֮ǰ�ľ�ֵ
	}


	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}

	//��ֵ���������
	/*
	��ֵ�������Ҫע��ļ���
	1.��������
	2.����ֵ
	3.����Լ����Լ���ֵ
	4.����*this
	5.���û����ʾ���帳ֵ���������,�������Ҳ������һ��,������ǳ����
	*/
	Date& operator=(const Date& d){
		if (this != &d)//�ų��Լ����Լ���ֵ�����
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//ע�ⷵ��ֵΪ����
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 10;
	int c = 100;

	a = b = c;//����������ֵ
	Date d1(2019, 6, 16);
	Date d2(2019, 6, 17);
	Date d3(2019, 6, 18);
	Date& d4 = d1;
	d4 = d1;//�൱���Լ����Լ���ֵ
	//d1 = d2;   //�ȼ��� d1.operator=(d2); //  �ײ�Date::operator=(&d1, d2);

	//d1 = d2 = d3;  //ʵ���ϵĸ�ֵ˳��:d1 = (d2 = d3)
	d1.operator=(d2.operator=(d3));

	return 0;
}
/*
C++Ϊ�˼�ǿ����Ŀɶ������������������,����������Ǿ������⺯�����ĺ���
Ҳ�����䷵��ֵ,��������������б�,�䷵��ֵ������б�����ͨ��������
��������Ϊ:�ؼ���operator�������Ҫ���ص�������ķ���
����ԭ��:����ֵ����operator������(�����б�)
ע��:
����ͨ������������������������µĲ�����,��operator@
���ز�����������һ�������ͻ���ö�����͵Ĳ�����,������Ҫ��һ���Զ������͵Ĳ���
�����������͵Ĳ�����,�京�岻�ܸı�,����:���õ�����+,���ܸı��京��
��Ϊ���Ա�����غ���ʱ,���βο������Ȳ�������Ŀ��1,��Ա�����Ĳ�����
��һ��Ĭ�ϵ��β�this,�޶�Ϊ��һ���β�
.*   ;;   sizeof  ?:   .
�����������������γ�����
*/


#endif
class Date
{
public:
	Date(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}

	// const��Ա�����в����޸ĳ�Ա����
	// const����thisָ�룬��������ǰ�����е����ݲ������޸�

	

	// thisָ�������Date* const  ����thisָ�벻���޸�,���ǳ�Ա���������޸�
	void PrintDate()
	{
		_day = 1;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// thisָ�������const Date* const  ����thisָ��ָ��ĵ�ַ�͵�ַ��������ݶ������޸�
	void PrintDate()const
	{
		//this->_day = 1;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//�����������������γ�����


	bool operator==(const Date& d)const
	{
		//_day = 1;
		//d._day = 1;
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main(){
	Date d(2019, 7, 17);
	d.PrintDate();
	cout << &d << endl;
	return 0;
}

/*
ע��:
1.const���󲻿��Ե��÷�const��Ա����,���Ƿ�const������Ե���const��Ա����,�൱��ֻ��
2.const��Ա�����ڲ����Ե���������const��Ա����,���Ƿ�const��Ա�����ڿ��Ե���������const��Ա����

*/

