//迷宫问题
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#define INITCAPACITY 10

typedef struct Coordinate
{
	int x;
	int y;
}Coor;

/////////////////////////////////////////////////////////////////
typedef Coor STD;

typedef struct Stack
{
	STD*base;
	int top;
	int capacity;
}S;

void InitStack(S*pf)
{
	pf->base = (STD*)malloc(sizeof(STD)*INITCAPACITY);
	pf->capacity = INITCAPACITY;
	pf->top = 0;
}
void checkcapacity(S*pf)
{
	assert(pf);
	if (pf->top == pf->capacity)
	{
		pf->capacity *= 2;
		pf->base = (STD*)realloc(pf->base, pf->capacity * sizeof(STD));
	}
}
void StackPush(S*pf, STD n)
{
	checkcapacity(pf);
	pf->base[pf->top] = n;
	pf->top++;
}

void StackPop(S*pf)
{
	assert(pf&&pf->top > 0);
	pf->top--;
}

bool StackEmpty(S*pf)
{
	assert(pf);
	if (pf->top == 0)
		return true;
	else
		return false;
}
void StackDestory(S*pf)
{
	assert(pf);
	pf->capacity = pf->top = 0;
	free(pf->base);
	pf->base = NULL;
}
STD StackTop(S*pf)
{
	assert(pf&&pf->top > 0);
	return pf->base[pf->top - 1];
}
int StackSize(S*pf)
{
	assert(pf);
	return pf->top;
}
/////////////////////////////////////////////////////////////////
S Path;

bool checkCoor(int**maze, int N, int M, Coor coor)
{
	if ((coor.x >= 0 && coor.x < N)
		&& (coor.y >= 0 && coor.y < M)
		&& maze[coor.x][coor.y] == 0)
		return true;
	else
		return false;
}
bool SearchmazePath(int**maze, int N, int M, Coor coor)
{
	StackPush(&Path, coor);
	if (coor.x == N - 1 && coor.y == M - 1)
		return true;

	Coor next;
	maze[coor.x][coor.y] = 2;

	next = coor;
	next.y += 1;
	if (checkCoor(maze, N, M, next))
	{
		if (SearchmazePath(maze, N, M, next))
			return true;
	}

	next = coor;
	next.y -= 1;
	if (checkCoor(maze, N, M, next))
	{
		if (SearchmazePath(maze, N, M, next))
			return true;
	}
	next = coor;
	next.x -= 1;
	if (checkCoor(maze, N, M, next))
	{
		if (SearchmazePath(maze, N, M, next))
			return true;
	}
	next = coor;
	next.x += 1;
	if (checkCoor(maze, N, M, next))
	{
		if (SearchmazePath(maze, N, M, next))
			return true;
	}

	StackPop(&Path);
	return false;
}
void PrintPath(S*path)
{
	S rpath;
	InitStack(&rpath);
	while (!StackEmpty(path))
	{
		StackPush(&rpath, StackTop(path));
		StackPop(path);
	}
	while (!StackEmpty(&rpath))
	{
		Coor c = StackTop(&rpath);
		printf("(%d,%d)\n", c.x, c.y);
		StackPop(&rpath);
	}
	StackDestory(&rpath);
}
int main()
{
	int N, M;
	while (~scanf("%d %d", &N, &M))
	{
		//输入结束后按Ctrl+Z
		int**maze = (int**)malloc(sizeof(int*)*N);
		for (int i = 0; i < N; i++)
			maze[i] = (int*)malloc(sizeof(int)*M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				scanf("%d ", &maze[i][j]);
		}
		InitStack(&Path);
		Coor start = { 0,0 };
		if (SearchmazePath(maze, N, M, start))
		{
			printf("找到出口了,路径如下:\n");
			PrintPath(&Path);
		}
		else
			printf("没有找到出口\n");
		StackDestory(&Path);
		for (int i = 0; i < N; i++)
			free(maze[i]);
		free(maze);
		maze = NULL;
	}
	return 0;
}
