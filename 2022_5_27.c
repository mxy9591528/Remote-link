#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef struct Coordinate
{
	int row;
	int col;
}Coor;
/////////////////////////////////////////////////////////////////
typedef Coor STD;

typedef struct Stack
{
	STD* base;
	int top;
	int capacity;
}S;

void StackInit(S* ps)
{
	assert(ps);

	ps->base = (STD*)malloc(sizeof(STD) * 4);
	if (ps->base == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	ps->capacity = 4;
	ps->top = 0;
}

void StackDestory(S* ps)
{
	assert(ps);
	free(ps->base);
	ps->base = NULL;
	ps->top = ps->capacity = 0;
}

// 入栈
void StackPush(S* ps, STD x)
{
	assert(ps);

	// 满了-》增容
	if (ps->top == ps->capacity)
	{
		STD* tmp = (STD*)realloc(ps->base, ps->capacity * 2 * sizeof(STD));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->base = tmp;
			ps->capacity *= 2;
		}
	}

	ps->base[ps->top] = x;
	ps->top++;
}

// 出栈
void StackPop(S* ps)
{
	assert(ps);
	// 栈空了，调用Pop，直接中止程序报错
	assert(ps->top > 0);

	//ps->a[ps->top - 1] = 0;
	ps->top--;
}

STD StackTop(S* ps)
{
	assert(ps);
	// 栈空了，调用Top，直接中止程序报错
	assert(ps->top > 0);

	return ps->base[ps->top - 1];
}

int StackSize(S* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(S* ps)
{
	assert(ps);

	return ps->top == 0;
}

S path;
S minpath;
////////////////////////////////////////////////////////////////

// 输出栈里面的坐标路径
void PirntPath(S* ps)
{
	// path数据倒到rPath
	S rPath;
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		StackPush(&rPath, StackTop(ps));
		StackPop(ps);
	}
	while (StackSize(&rPath) > 1)
	{
		Coor top = StackTop(&rPath);
		printf("[%d,%d],", top.row, top.col);
		StackPop(&rPath);
	}
	Coor top = StackTop(&rPath);
	printf("[%d,%d]", top.row, top.col);
	StackPop(&rPath);
	StackDestory(&rPath);
}

bool checkCoor(int** maze, int N, int M, Coor pos)
{
	if (pos.row >= 0 && pos.row < N
		&& pos.col >= 0 && pos.col < M
		&& maze[pos.row][pos.col] == 1)
		return true;
	else
		return false;
}

void StackCopy(S* ppath, S* pcopy)
{
	pcopy->base = (STD*)malloc(sizeof(STD*)*ppath->capacity);
	memcpy(pcopy->base, ppath->base, sizeof(STD)*ppath->top);
	pcopy->top = ppath->top;
	pcopy->capacity = ppath->capacity;
}

void SearchmazePath(int** maze, int N, int M, Coor cur, int P)
{
	StackPush(&path, cur);

	// 如果走到出口
	if (cur.row == 0 && cur.col == M - 1)
	{
		// 找到了更短的路径，更新minpath；
		if (P >= 0 && StackEmpty(&minpath)
			|| StackSize(&path) < StackSize(&minpath))
		{
			StackDestory(&minpath);
			StackCopy(&path, &minpath);
		}
	}
	// 探测cur位置得上下左右四个方向
	Coor next;
	maze[cur.row][cur.col] = 2;
	// 上
	next = cur;
	next.row -= 1;
	if (checkCoor(maze, N, M, next))
		SearchmazePath(maze, N, M, next, P - 3);
	// 下
	next = cur;
	next.row += 1;
	if (checkCoor(maze, N, M, next))
		SearchmazePath(maze, N, M, next, P);
	// 左
	next = cur;
	next.col -= 1;
	if (checkCoor(maze, N, M, next))
		SearchmazePath(maze, N, M, next, P - 1);
	// 右
	next = cur;
	next.col += 1;
	if (checkCoor(maze, N, M, next))
		SearchmazePath(maze, N, M, next, P - 1);
	// 恢复一下
	maze[cur.row][cur.col] = 1;
	StackPop(&path);
}

int main()
{
	int N = 0, M = 0, P = 0;
	while (scanf("%d%d%d", &N, &M, &P) != EOF)
	{
		// int a[n][m]; // vs2013 不支持
		// 动态开辟二维数组
		int** maze = (int**)malloc(sizeof(int*)*N);
		for (int i = 0; i < N; ++i)
		{
			maze[i] = (int*)malloc(sizeof(int)*M);
		}
		// 二维数组得输入
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &maze[i][j]);
			}
		}
		StackInit(&path);
		StackInit(&minpath);
		Coor start = { 0, 0 };
		SearchmazePath(maze, N, M, start, P);
		if (!StackEmpty(&minpath))
		{
			printf("找到出口了，路径如下:\n");
			PirntPath(&minpath);
		}
		else
			printf("Can not escape!\n");
		StackDestory(&path);
		StackDestory(&minpath);
		for (int i = 0; i < N; ++i)
			free(maze[i]);
		free(maze);
		maze = NULL;
	}
	return 0;
}