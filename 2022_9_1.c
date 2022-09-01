//Á´Õ»
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef char ElemType;
typedef struct LinkNode
{
	ElemType*data;
	struct LinkNode*next;
}Node;
typedef struct
{
	Node*top;
	int size;
}LinkStack;
void InitStack(LinkStack*ls)
{
	ls->size = 0;
	ls->top = NULL;
}
void push(LinkStack*ls, ElemType e)
{
	Node*node = (Node*)malloc(sizeof(Node));
	node->data = e;
	node->next = ls->top;
	ls->top = node;
	ls->size++;
}
void pop(LinkStack*ls, ElemType*back)
{
	if (ls->size == 0)
		return;
	*back = ls->top->data;
	Node*p = ls->top;
	ls->top = ls->top->next;
	free(p);
	p = NULL;
	ls->size--;
}
ElemType top(LinkStack*ls)
{
	return ls->top->data;
}

void calc()
{
	LinkStack s;
	InitStack(&s);
	int k = 0;
	ElemType*num=(ElemType*)malloc(sizeof(ElemType));
	char str[100] = "";
	char bstr[100] = "";
	gets(str);
	for (int i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]))
			bstr[k++] = str[i];
		else
		{
			if (str[i] == ')')
			{
				while (s.top->data != '(')
				{
					bstr[k++] = s.top->data;
					pop(&s, num);
				}
				pop(&s, num);
			}
			else
				push(&s, str[i]);
		}
	}
	for (int i = 0; i < strlen(bstr); i++)
		printf("%c", bstr[i]);
}
int main()
{
	calc();
	LinkStack s;
	ElemType*num = (ElemType*)malloc(sizeof(ElemType));
	InitStack(&s);
	for (int i = 0; i < 100; i++)
		push(&s, i);
	for (int i = 0; i < 100; i++) {
		pop(&s, num);
		printf("%d ", *num);
	}
	free(num);
	num = NULL;
}
