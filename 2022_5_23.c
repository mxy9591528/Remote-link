#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int QUD;

typedef struct QueueNode
{
	QUD data;
	struct QueueNode*next;
}QNode;

typedef struct Queue
{
	QNode*head;
	QNode*tail;
}Queue;

void QueueInit(Queue*q)
{
	q->head = q->tail = NULL;
}
int QueueEmpty(Queue*q)
{
	return q->head == NULL;
}
void push(Queue*q, QUD x)
{
	QNode*node = (QNode*)malloc(sizeof(QNode));
	node->data = x;
	node->next = NULL;
	if (q->head == NULL)
		q->head = q->tail = node;
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
}
void pop(Queue*q)
{
	if (!QueueEmpty(q))
	{
		printf("%d\n", q->head->data);
		QNode*temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
	else
		printf("error\n");
}
void front(Queue*q)
{
	if (!QueueEmpty(q))
		printf("%d\n", q->head->data);
	else
		printf("error\n");
}
void QueueDestory(Queue*q)
{
	QNode*cur = q->head;
	while (cur)
	{
		QNode*temp = cur->next;
		free(cur);
		cur = temp;
	}
}
int main()
{
	Queue q;
	QueueInit(&q);
	int n;
	scanf("%d", &n);
	char key[10];
	int x;
	while (n--)
	{
		scanf("%s", key);
		if (!strcmp(key, "push"))
		{
			scanf("%d", &x);
			push(&q, x);
		}
		if (!strcmp(key, "pop"))
			pop(&q);
		if (!strcmp(key, "front"))
			front(&q);
	}
	QueueDestory(&q);
	return 0;
}