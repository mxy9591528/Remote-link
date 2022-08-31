//静态链表
#include<stdio.h>
#define MAX_SIZE 1000
#define ERROR -1
#define OK 1
typedef int ElemType;
typedef int Status;
typedef struct
{
	ElemType data;
	int index;
}S_list, Static_LinkList[MAX_SIZE];
Status InitList(S_list*sl)
{
	for (int i = 0; i < MAX_SIZE - 1; i++)
		sl[i].index = i + 1;
	sl[MAX_SIZE - 1].index = 0;
	return OK;
}
int Malloc_sl(S_list*s)
{
	int tmp = s[0].index;//使用备用元素,存储的为空闲位置的下标
	if (tmp)
		s[0].index = s[tmp].index;//更新备用元素
	return tmp;
}
int ListLength(S_list*s)
{
	int cnt = 0;
	int i = s[MAX_SIZE - 1].index;
	while (i)
	{
		i = s[i].index;
		cnt++;
	}
	return cnt;
}
Status ListInsert(S_list*s,int num,ElemType e)
{
	int j, k;
	k = MAX_SIZE - 1;
	if (num<1 || num>ListLength(s)+1)
		return ERROR;
	j = Malloc_sl(s);
	if (j)
	{
		s[j].data = e;
		for (int l = 1; l < num; l++)
			k = s[k].index;
		s[j].index = s[k].index;
		s[k].index = j;
		return OK;
	}
	return ERROR;
}

void Free_sl(S_list*s, int k)
{
	s[k].index = s[0].index;
	s[0].index = k;
}

Status ListDelete(S_list*s, int num)
{
	int j, k;
	if (num<1 || num>ListLength(s))
		return ERROR;
	k = MAX_SIZE - 1;
	for (int j = 1; j < num; j++)
		k = s[k].index;
	j = s[k].index;
	s[k].index = s[j].index;
	Free_sl(s,j);
	return OK;
}

void ShowList(S_list*s, int l, int r)
{
	for (int i = l; i <r; i++)
		printf("%d %d\n", s[i].data, s[i].index);
}
int main()
{
	Static_LinkList sl;
	InitList(sl);
	for (int i = 1; i < 500; i++)
		ListInsert(sl, i, i);
	ShowList(sl, 0, 500);
	printf("%d\n", ListLength(sl));
	for (int i = 0; i < 250; i++)
		ListDelete(sl, i);
	ShowList(sl, 0, 250);
	printf("%d\n", ListLength(sl));
	return 0;
}
