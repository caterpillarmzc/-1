void Func(int n){
	int count = 0;
	for (int i = 0; i < n;++i){
		for (int j = 0; j < n;++j){
			++count;
		}
	}
	for (int k = 0; k < 2 * n;++k){
		++count;
	}
	int m = 10;
	while (m--){
		++count;
	}
	printf("%d\n", count);
}


int *a = (int*)malloc(n);//���Ͽ��ٺ�n��صĿռ�
int a[n];//ջ�Ͽ��ٿռ�
//�ݹ麯��,����ջʱռ�ÿռ��n�Ĺ�ϵ

long long Fib(int n){
	if (n<2){
		return n;
	}
	return Fib(n - 1) + Fib(n - 2);
}
