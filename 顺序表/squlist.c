#include "Seqlist.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void SeqListInit(SeqList*ps,int capacity){
	//ps�����Ǳ����ĵ�ַ,��Ϊ��
	assert(ps != NULL);
	if (ps != NULL);
	
	ps->array = malloc(sizeof(int)*capacity);
	assert(ps->array != NULL);
	ps->size = 0;
	ps->capacity = capacity;
}

void SeqListDestroy(SeqList *ps){
	//�ͷ�array�Ŀռ�
	free(ps->array);
}