//string�����ĳ�������
void TestString(){
	string s1;//����յ�string�����
	string s2("hello world");//��c��ʽ�ַ�������string�����s2
	string s3(s2);//��������s3
}


void TestString1(){
	//string�����֧��ֱ����cin��cout������������
	string s("hello world!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s << endl;

	//��s�е��ַ������,ע�����֪ʶ��size����,���ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;

	//��s����Ч�ַ��������ӵ�10��,���λ����'a'����
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//��s����Ч�ַ�������С��5��
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

}

void TestString2(){
	string s;
	//����reserve�Ƿ��ı�string�е���ЧԪ�ظ���
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//����reserve����С��string�ĵײ�ռ��С,�Ƿ�Ὣ�ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

//����reserve��߲������ݵ�Ч��,�������ݴ����Ŀ���
void TestPushBackReserve(){
	string s;
	s.reserve(100);
	size_t sz = s.capacity();

	cout << "making s growK\n";
	for (int i = 0; i < 100;++i){
		s.push_back('c');
		if (sz!=s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}