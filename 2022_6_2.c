#include <stdio.h>
#include<stdlib.h>
void main()
{
	int a = 0, b = 0, i = 0, j = 0;
	printf("请输入数组行数\n");
	scanf("%d", &a);
	printf("请输入数组列数\n");
	scanf("%d", &b);

	int**array = (int**)malloc(sizeof(int*)*a);
	for (i = 0; i < b; i++)
		array[i] = malloc(sizeof(sizeof(int)*b));

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			printf("请输入第%d行%d列元素：\n", i + 1, j + 1);
			scanf("%d", &array[i][j]);
		}
	}
	printf("\n====输入完毕====\n");

	int maxi, maxj = 0, mini = 0, minj, x, y, x_i, y_j;
	for (i = 0; i < a; i++)
	{
		maxi = 0;
		for (j = 0; j < b; j++)
		{
			if (maxi < array[i][j])
			{
				maxi = array[i][j];
				x = i;
				y = j;
			}
		}
		if (!mini || mini > maxi)
		{
			mini = maxi;
			x_i = x;
			y_j = y;
		}
	}
	printf("各行最大之最小为%d,下标%d %d\n", mini, x_i, y_j);
	for (i = 0; i < b; i++)
	{
		minj = INT_MAX;
		for (j = 0; j < a; j++)
		{
			if (minj > array[j][i])
			{
				minj = array[j][i];
				x = j;
				y = i;
			}
		}
		if (!maxj || maxj < minj)
		{
			maxj = minj;
			x_i = x;
			y_j = y;
		}
	}
	printf("各列最小之最大为%d,下标%d %d\n", maxj, x_i, y_j);
}