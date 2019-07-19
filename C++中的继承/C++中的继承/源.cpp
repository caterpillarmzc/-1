using namespace std;
#include <iostream>
#include <string>
#if 0
//�̳�
/*
�̳���ʹ���븴�õ���Ҫ�ֶ�,�����ڱ���ԭ�������ԵĻ����Ͻ�����չ
���ӹ���,�����������Ϊ������,����Ҳ��Ϊ����
*/

//����
class Person
{
public:
	void Print(){
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "mike";
	int _age = 18;

};

//������1
class Student:public Person//ע���ʽ,:public��ʾ�̳з�ʽ,�������public�Ļ�,classĬ����private,structĬ����public
{
protected:
	int _sutID;
};

//������2
class Teacher:public Person
{
protected:
	string _job;
};
/*
�̳к���ĳ�Ա(��Ա����+��Ա����)�����������һ����
���������ิ���˸���ĳ�Ա
�ܽ�:
1.����private��Ա���������в����Ժ��ּ̳з�ʽ���ǲ��ɼ���,
���ɼ���ָ�����˽�г�Ա���Ǽ̳е�����������,�����﷨����
������������������ڻ������ⶼ���ܷ�����
2.����private��Ա���������в��ܱ�����,������۳�Ա���뱻�����ⱻ����
������Ҫ���������п��Ա�����,�Ͷ���Ϊprotected,���Ա�����Ա�޶�������Ϊ�̳ж����ֵ�
3.���ʷ�ʽ:public>protected>private,ʵ����һ�㶼����public�̳�,��������������
*/
#endif


#if 0
//��������������ֵת��
/*
�����������Ը�ֵ������Ķ���/�����ָ��/���������,
���ǻ�������ܸ�ֵ�����������
�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��,
���Ǳ����ǻ����ָ����ָ������������ǲ��ǰ�ȫ��*/

class Person
{
public:
	void Print(){
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "mike";
	int _age = 18;

};

class Student :public Person//ע���ʽ,:public��ʾ�̳з�ʽ,�������public�Ļ�,classĬ����private,structĬ����public
{
public:
	int _sutID;
};
void Test(){
	//1.���������Ը�ֵ���������/ָ��/����
	Student sobj;
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.��������ܸ�ֵ�����������
	//sobj = pobj;

	//3.�����ָ�����ͨ��ǰ������ת����ֵ���������ָ��
	pp = &sobj;
	Student* ps1 = (Student*)pp;//ת��Ϊ�������ָ��
	ps1->_sutID = 10;
}

int main(){
	void Test();
}


#endif


#if 0


//�̳��е�������
/*1.�ڼ̳���ϵ�л���������඼�ж�����������
2.����͸�������ͬ����Ա,�����Ա�����θ����ͬ����Ա��ֱ�ӷ���
�������������,Ҳ���ض���,(�������Ա������,����ʹ�� ����::�����Ա  ��ʾ����)
ֻҪ��������ͬ�͹�������,ʵ��ʹ����ò�Ҫ����ͬ������*/

//�����������Ĭ�ϳ�Ա��
/*������Ĺ��캯��������û���Ĺ��캯������ʼ�����ڻ������һ���ֳ�Ա
�������û��Ĭ�ϵĵĹ��캯��,������������๷�������ĳ�ʼ���б���ʽ����
ͬ��,������Ŀ������캯���͸�ֵ�����������Ҳ��Ҫ���û��������ɻ�����һ���ֳ�Ա�Ĳ���
������������������ڱ��������֮���Զ����û������������,�������ܱ�֤���������������������
����������ʼ���ȵ��û��๹���ٵ��������๹��
��������������ȵ��û���������ٵ��û�������,��Ϊ��Ҫ�ȳ�ʼ������,�ٵ���������*/
//����
class Base
{
public:
	Base(int b)//���๹�캯��
		:_b(b)
	{
		cout << "Base(int)" << endl;
	}

	Base(Base& b)//���࿽�����캯��
		:_b(b._b)
	{
		cout << "Base(Base)" << endl;
	}

	Base& operator=(const Base& b){
		if (this!= &b)
		{
			_b = b._b;//�û���������ǰ����ֵ
		}
		return *this;
	}

	~Base(){
		cout << "Base()" << endl;
	}
protected:
	int _b;

};
//������
class Derived:public Base
{
public:
	Derived(int b,int d)
		:Base(b)//��ʾ�����๹�캯������
		,_d(d)//�ٳ�ʼ���Լ��ĳ�Ա
	{
		cout << "derived(int)" << endl;
	}
	Derived(Derived& d)
		:Base(d)//��ʾ���û��࿽�����캯��
		,_d(d._d)
	{
		cout << "Derived(Derived&)" << endl;
	}
	Derived& operator-(const Derived& d){
		if (this!=&d)
		{
			Base::operator=(d);//�û���ĸ�ֵ��ʼ������Ĳ���
			_d = d._d;
		}
		return *this;
	}
	~Derived(){
		cout << "Derived()" << endl;
		//�Զ����û������������
		//call Base::~Base();
	}
protected:
	int _d;

};

int main(){
	Derived d1(10,20);
	Derived d2(d1);
	Derived d3(30,40);
	d1 = d3;
	return 0;
}

#endif


#if 0
//��Ԫ��ϵ���ܼ̳�,Ҳ����˵������Ԫ���ܷ��������˽�кͱ�����Ա
class Base
{
	friend void Print();//�������Ԫ����
public:
	Base(int b=0)//���๹�캯��
		:_b(b)
	{ }
protected:
	int _b;
};

class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
private:
	int _d;
};
void Print(){
	Base b;
	b._b = 10;
	Derived d(1, 2);
	//d._d = 10;   //��Ԫ��ϵ���ܼ̳�,���ܷ���������
}
int main(){
	void Print();
}


#endif

