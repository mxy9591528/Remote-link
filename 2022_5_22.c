#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LinkList
{
	int val;
	struct LinkList*next;
}L;
void InitLink(L*p)
{
	p->next = NULL;
}
L*searchnode(L*p, int n)
{
	while (p->next)
	{
		if (p->next->val == n)
			return p;
		p = p->next;
	}
	return p;
}
void insertnode(L*p, int x, int y)
{
	L*prev = searchnode(p, x);
	L*node = (L*)malloc(sizeof(L));
	node->val = y;
	if (prev->next != NULL)
	{
		node->next = prev->next;
		prev->next = node;
	}
	else
	{
		prev->next = node;
		node->next = NULL;
	}
}
void deletenode(L*p, int n)
{
	L*prev = searchnode(p, n);
	if (prev->next != NULL)
	{
		L*ret = prev->next->next;
		free(prev->next);
		prev->next = ret;
	}
}
int main()
{
	int n, x, y;
	char key[10];
	scanf("%d", &n);
	L*p = (L*)malloc(sizeof(L));
	InitLink(p);
	while (n--)
	{
		scanf("%s", key);
		if (!strcmp(key, "insert"))
		{
			scanf("%d", &x);
			scanf("%d", &y);
			insertnode(p, x, y);
		}
		if (!strcmp(key, "delete"))
		{
			scanf("%d", &x);
			deletenode(p, x);
		}
	}
	L*cur = p;
	if (cur->next == NULL)
		printf("NULL");
	while (cur->next)
	{
		cur = cur->next;
		printf("%d ", cur->val);
	}
	return 0;
}