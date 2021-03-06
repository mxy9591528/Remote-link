#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef	BTNode* QUD;

typedef struct QueueNode
{
	struct QueueNode*next;
	QUD data;
}Qnode;
typedef struct Queue
{
	Qnode*head;
	Qnode*tail;
}Queue;
void QueueInit(Queue*p)
{
	assert(p);
	p->head = p->tail = NULL;
}
void QueuePush(Queue*p, QUD n)
{
	assert(p);
	Qnode*node = (Qnode*)malloc(sizeof(Qnode));
	node->next = NULL;
	node->data = n;
	if (p->tail == NULL)
	{
		p->head = p->tail = node;
	}
	else
	{
		p->tail->next = node;
		p->tail = node;
	}
}
void QueuePop(Queue*p)
{
	assert(p&&p->head);
	if (p->head->next == NULL)
	{
		free(p->head);
		p->head = p->tail = NULL;
	}
	else
	{
		Qnode*temp = p->head->next;
		free(p->head);
		p->head = temp;
	}
}
QUD QueueFront(Queue*p)
{
	assert(p&&p->head);
	return p->head->data;
}
QUD QueueBack(Queue*p)
{
	assert(p&&p->head);
	return p->tail->data;
}
void QueueDestory(Queue*p)
{
	assert(p);
	Qnode*cur = p->head;
	while (cur)
	{
		Qnode*temp = cur->next;
		free(cur);
		cur = temp;
	}
	p->head = p->tail = NULL;
}
bool QueueEmpty(Queue*p)
{
	return p->head == NULL;
}
int QueueSize(Queue*p)
{
	assert(p);
	int size = 0;
	Qnode*cur = p->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}