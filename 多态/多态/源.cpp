#include <iostream>
using namespace std;
#if 0


class Person{
public:
	virtual void BuyTicket(){
		cout << "buy ticket " << endl;
	}
};

class Student:public Person{
public:
	virtual void BuyTicket(){
		cout << "buy ticket " << endl;
	}
};


class A
{
public:
	virtual void f() final {}
};
class B :public A
{
public:
	virtual void f(){}

};
class Person{
public:
	virtual A* f(){
		return new A;
	}
};
class Student:public Person{
public:
	virtual B* f(){
		return new B;
	}
}; 


//����麯���Ƿ���д�������ؼ���
class A
{
public:
	virtual void f(){}
};
class B :public A
{
public:
	virtual void f()override{}

};


class A
{
public:
	virtual void f() final {}
};
class B :public A
{
public:
	virtual void f(){}

};
#endif

#if 0


class Person
{
public:
	virtual void Ticket() = 0;
};

class Student :public Person
{
public:
	virtual void Ticket()
	{
		cout << "50% off" << endl;
	}
};

class Soldier :public Person
{
public:
	virtual void Ticket()
	{
		cout << "first priority " << endl;
	}
};

void Test(){
	Person* pStudent = new Student;
	pStudent->Ticket();

	Person* pSoldier = new Soldier;
	pSoldier->Ticket();
}

int main(){
	Test();
	return 0;
}
#endif

class Base
{
public:
	virtual void Func(){
		cout << "Func()" << endl;
	}
	virtual void Func2(){
		cout << "Func2()" << endl;
	}
	void Func3(){
		cout << "Func3()" << endl;
	}
private:
	int _b = 1;
};

class Dev :public Base
{
public:
	virtual void Func(){
		cout << "Func()" << endl;
	}
	virtual void Func4(){
		cout << "Func4()" << endl;
	}
private:
	int _d = 2;
};

//��ӡ���
//����������ָ�������,������Դ�ӡ��������,�����Դ�ӡ����������.
//��������ÿ���ֱ������������Ķ���
typedef void(*P)();
void Print(Base &b)
{//�Ӷ����ǰ�ĸ��ֽ��л�ȡ���ĵ�ַ
	P* p=(P*)*(int*)&b;//��P*���͵ı���p��ת���ĵ�ַ����һ��
//ͨ�����ָ���ȡ�麯������ڵ�ַ������
	while (*p)
	{
		(*p)();//��p���ָ�������,�൱�ڵ��øú���
		++p;
	}
}

int main(){
	Base b;
	Dev d;
	cout << "Base:" << endl;
	Print(b);
	cout << "Dev:" << endl;
	Print(d);
	return 0;
}