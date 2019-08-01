#include <iostream>
using namespace std;

//����ָ��,�Զ��ͷ���Դ
//RAII������Դ+��*��->����,ʵ��ָ��Ĺ���
//�����Ǵ���ǳ����������
#if 0
//��һ�������ռ�
namespace Raii
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)//��������,ʹ֮ǰ�Ķ�������Դ�Ͽ���ϵ
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;//ʹ֮ǰ�Ķ�������Դ�Ͽ���ϵ
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)//��ֵ���������
		{
			if (this!=&ap)//����Ƿ�Ϊ�Լ����Լ���ֵ
			{
				if (_ptr)
					delete _ptr;//����Ѿ�������Դ,��ԭ������Դ�ͷ�
				_ptr = ap._ptr;//ת����Դ
				ap->_ptr = nullptr;
			}
		}

		~auto_ptr()//��������
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		//��������ָ�����Ϊ
		T* operator->()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
	};
private:
	T* _ptr;
}

//ֱ��ͨ��ap1��ap2��������,��������ʹ��ͬһ����Դ,���ͷ�ʱ�ͻ���Ϊ����ͷŵ��´��뱼��
void TestAuto1()
{
	int a = 10;
	int* pa1 = &a;
	int* pa2(pa1);

	*pa1 = 20;//�����÷��ʵ���ʵ��
	*pa2 = 30;

	Raii::auto_ptr<int> ap1(new int);
	Raii::auto_ptr<int> ap2(ap1);
	*ap1 = 10;
	*ap2 = 20;//ap1��ap2ͬʱ������Դ�����----->ȱ��


	Raii::auto_ptr<int> ap3;
	ap3 = ap2;
}

int main(){
	TestAuto1();
	return 0;
}



#endif

#if 0
//�Ľ�---->��Դ����Ȩ��ת��,����Դ�����ͷŵ�Ȩ��,���ö�������Դ��ȫ�����ϵ
//mutable bool _owner;  // ��Դ������ӵ����(��Դ���ͷ���),����״̬:true��false

namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _owner(false)//�ȸ�Ȩ��Ϊfalse
		{
			if (_ptr)
			{
				_owner = true;//����û��ṩ��Դ,��Ϊtrue
			}
		}

		~auto_ptr()
		{
			if (_ptr && _owner)//����Դ+��Ȩ��
			{
				delete _ptr;
				_owner = false;
				_ptr = nullptr;
			}
		}

		// ����ָ�����Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

		auto_ptr(const auto_ptr<T>& ap)
			: _ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;//֮ǰ�Ķ������Դû�����ͷ�Ȩ
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr && _owner)//����Դ+��Ȩ��
				{
					delete _ptr;
				}

				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}

			return *this;
		}
	private:
		T* _ptr;
		mutable bool _owner;  // ��Դ������ӵ����(��Դ���ͷ���)
		//mutable���Ըı䱻const���ζ���
	};
}

//ʵ����
void TestAutoPtr()
{
	bite::auto_ptr<int> ap1(new int);
	bite::auto_ptr<int> ap2(ap1);

	*ap1 = 10;
	*ap2 = 20;//��ʱ����ͬʱ������Դ,������Դ���ͷ�һ��

	bite::auto_ptr<int> ap3;
	ap3 = ap2;

	//ȱ��
	if (true)
	{
		// ap3����Դ�Լ����ͷ�Ȩ��ת�Ƹ�ap4
		// ap4������ʱ�Ѿ�����Դ�ͷ���,��ʱ�����
		bite::auto_ptr<int> ap4(ap3);
	}

	// Ұָ��
	*ap3 = 10;
}


#endif



//��Դ��ռ,�������������͸�ֵ������ָ��unique_ptr
//ȱ��:��֧�ֿ�����ֵ
#if 0

namespace bite
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// ��ֹ������
		// C++98
		//private:ֻ����������,����˽��
		//	unique_ptr(const unique_ptr<T>&);ֻ����������
		//	unique_ptr<T>& operator=(const unique_ptr<T>& ap);

		// C++11 delete:��ֹĬ�ϳ�Ա����������
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;

	private:
		T* _ptr;
	};
}

class A
{
public:
	A(int a)
		: _a(a)
	{}

	A() = default;


private:
	int _a;
};

void TestA()
{
	A a1(10);
	A a2;
}

void TestUniquePtr()
{
	bite::unique_ptr<int> up1(new int);
	//bite::unique_ptr<int> up2(up1);

	bite::unique_ptr<int> up3;
	//up3 = up1;
}

#endif

//shared_ptr��������������ָ��
/*
share_ptr��ԭ��:ͨ�����ü����ķ�ʽ��ʵ�ֶ��share_ptr����֮�乲����Դ
1.share_ptr�����ڲ�,��ÿ����Դ��ά����һ�ݼ���,������¼�÷���Դ������������
2.�ڶ�������ʱ(Ҳ����������������),��˵���Լ���ʹ�ø÷���Դ��,��������ü�����һ
3.������ü�����0,��˵���Լ������һ��ʹ�ø÷���Դ�Ķ���,�����ͷŸ���Դ
4.�������0,��˵�����ж�����ʹ�ø���Դ,�����ͷ���Դ,��������Ұָ��
5.share_ptr����Ҳ����ǳ��������,������Դ�����һ��ʹ�õĶ������ͷ�
*/

#if 0
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{
			if (_ptr)
				_count = 1;
		}

		shared_ptr(shared_ptr<T>& sp)
			: _ptr(sp._ptr)
		{
			_count++;
		}

		~shared_ptr()
		{
			if (_ptr && 0 == --_count)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
	private:
		T* _ptr; // ��Դ
		static int _count;
	};

	template<class T>
	int shared_ptr<T>::_count = 0;
}

void TestSharedPtr()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);

	bite::shared_ptr<int> sp3(new int);
}


int main()
{
	TestSharedPtr();
	return 0;
}
#endif

#if 0


namespace bite
{
	// ֻ�ܹ���new����Դ
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)//�û�����Դ,count����1
				_pCount = new int(1);
		}

		//��������,��Դ����,����ָ�빲��
		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)//��Դ���ڲ��ܸ�����ָ��������ټ�1,�������ж�
				++(*_pCount);
		}
		//�������:
		// sp2:û�й�����Դ --->��sp1ֱ�ӹ���
		// sp2: ���Թ�����Դ 
		// sp2: ��������������Դ  --->����-1
		// sp2 = sp1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// �õ�ǰ������֮ǰ�������Դ�Ͽ���ϵ
				release();

				// �õ�ǰ������sp������Դ
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
					++(*_pCount);
			}

			return *this;
		}

		~shared_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_pCount;//��ȡ���ü���
		}

	private:
		void release()
		{
			//���������Դ,����count--֮�����0,�ͷ���Դ
			if (_ptr && 0 == --*_pCount)
			{
				delete _ptr;
				_ptr = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}
	private:
		T* _ptr; // ��Դ
		int* _pCount;  // ָ������Ŀռ�
	};
}

void TestSharedPtr1()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	bite::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;
}

void TestSharedPtr2()
{
	// 	bite::shared_ptr<int> sp1(new int);
	// 	bite::shared_ptr<int> sp2;
	// 
	// 	// sp2û�й�����Դ
	// 	sp2 = sp1;

	// 	bite::shared_ptr<int> sp1(new int);
	// 	bite::shared_ptr<int> sp2(new int);
	// 	sp2 = sp1;

	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(new int);
	bite::shared_ptr<int> sp3(sp2);

	sp2 = sp1;
}

int main()
{
	//TestSharedPtr1();
	TestSharedPtr2();
	return 0;
}

//ȱ��:
// ������Դ�ǲ���delete��ʽ�����ͷ�
// ��ȷ�ͷŷ�ʽ��������Դ������ȥ�ͷ�
// ������Դʱ��������ʽ�������
#endif



//ʹ�÷º����Ľ�:��һ������԰��պ����ķ�ʽ���е���
// new
template<class T>
class DFDel
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

// malloc����Դ
template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

//�ļ�
class FClose
{
public:
	void operator()(FILE*& pf)
	{
		if (pf)
		{
			fclose(pf);
			pf = nullptr;
		}
	}
};
namespace bite
{
	template<class T, class DF = DFDel<T> >//ģ������б��м����ͷŵķº���
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
				_pCount = new int(1);
		}

		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)
				++(*_pCount);
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// �õ�ǰ�����������Դ�Ͽ���ϵ
				release();

				// �õ�ǰ������sp������Դ
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
					++(*_pCount);
			}

			return *this;
		}

		~shared_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		void release()
		{
			if (_ptr && 0 == --*_pCount)
			{
				//delete _ptr;
				//DF df;
				//df.operator()(_ptr);
				DF()(_ptr);//DF ���Ե���������,�����ͷ�

				_ptr = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}
	private:
		T* _ptr; // ��Դ
		int* _pCount;  // ָ������Ŀռ�
	};
}

void TestSharedPtr()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	bite::shared_ptr<FILE, FClose> sp3(fopen("1.txt", "w"));
}

int main()
{
	TestSharedPtr();
	return 0;
}