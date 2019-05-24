/**
* ����������ϰ
* ʵ��һ���ַ�������ÿ����һ���ַ���������������а��ֵ�������򣨲����ִ�Сд����a��aaǰ��aa��bǰ�ȣ���
* �ظ�������ַ����Զ����ԣ�
* ͨ�������ſ��Ի�ȡ����Ӧλ���ϵ��ַ�����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PRACTICE_LIST_H_
#define PRACTICE_LIST_H_
#if defined(__cplusplus) & __cplusplus
extern "C" {
#endif
#define ssize_t int	///<��������

	/**
	* ����ڵ����ݽṹ
	*/
	typedef struct tagLIST_NODE
	{

		char *str;
		struct tagLIST_NODE *next;

	}stLIST_NODE, *pstLIST_NODE;

	/**
	* �������ݽṹ
	*/
	typedef struct tagLIST
	{
		/**
		* ���������һ���ַ������ݡ�
		*
		* @return �ɹ����뷵��0���ظ����뷵��0��ʧ�ܷ���-1��
		*/
		int
		(*insert)(struct tagLIST *const list, const char *str);

		/**
		* ���������Ƴ�һ��ָ�����ַ������ݡ�
		*
		* @return �Ƴ��ɹ�����0�����򷵻�-1��
		*/
		int
			(*remove)(struct tagLIST *const list, const char *str);

		/**
		* ��������ĳ��ȡ�
		*/
		ssize_t
			(*length)(struct tagLIST *const list);

		/**
		* ����Ų��ҵ�������ϵ��ַ�����
		*
		* @return ����Ӧ��Ҫ�����ַ�������ַ������������峤��Ϊstacklen��stack�Ļ����в������ַ����ĳ��ȣ�\n
		*          ���򷵻�-1��
		*/
		ssize_t
			(*lookup)(struct tagLIST *const list, int id, char *stack, size_t stacklen);

		/**
		* ��˳���ӡ�����е��ַ������ݡ�
		*
		* @return �ޡ�
		*/
		void
			(*dump)(struct tagLIST *const list);

		struct tagLIST_NODE *next;	///<����һ��nextָ��,nextָ�������ַ�������Ľڵ����ݽṹ

	}stLIST, *pstLIST;

	/**
	* ��������
	*
	* @retval ������ �����ɹ���
	* @retval NULL ����ʧ�ܡ�
	*/
	extern pstLIST
		LIST_create();

	/**
	* �ͷ�����
	*
	* @param[in] list ��������
	*
	* @return �ޡ�
	*/
	extern void
		LIST_release(pstLIST list);

#if defined(__cplusplus) & __cplusplus
}
#endif
#endif
