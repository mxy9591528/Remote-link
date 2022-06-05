#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int getsum(int n)
{
	int sum = 0, ret = 0;
	while (n)
	{
		ret = n % 10;
		sum += (int)pow(ret, 3);
		n /= 10;
	}
	return sum;
}
int main()
{
	int n;
	FILE*fp;
	fp = fopen("out.txt", "w+");
	scanf("%d", &n);
	int*a = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{

		scanf("%d", &a[i]);

		if (a[i] == getsum(a[i]))
		{
			fprintf(fp, "%d ", a[i]);
		}
	}
	fclose(fp);
	fp = NULL;
	return 0;
}

#include<stdio.h>
#include<string.h>
struct day {
	int year;
	int month;
	int data;
};
struct Node {
	char name[20];
	char sex[10];
	struct day birthday;
	char address[100];
};
int main(void)
{
	struct Node node1 = { "wangchun","man",{2003,2,18},"China" };
	printf("姓名:%s,性别:%s,生日:%d年%d月%d日,住址:%s", node1.name, node1.sex, node1.birthday.year,node1.birthday.month,node1.birthday.data, node1.address);

}

#define M 21
#include<stdio.h>
int main()
{
	char a[M][M];
	int i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++)
			a[i][j] = '*';
	for (i = 0; i < M; i++)
		a[i][M/2] = 'H';
	for (i = 0; i < M; i++)
		a[M/2][i] = 'H';
	for (i = 0; i < M; i++)
		a[i][i] = 'H';
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++)
			if (i + j == M - 1)
				a[i][j] = 'H';
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include<ctype.h>
int fun(char s[])
{
	int count = 0, i=0;
	while (s[i])
	{
		if (isalpha(s[i]))
			count++;
		i++;
	}
	return count;
}
void main()
{
	char str[] = "Best wishes for you!";
	int k;
	k = fun(str);
	printf("k=%d\n", k);
}

#include<stdio.h>
int main()
{
	int ret;
	FILE*f;
	f=fopen("mydata.txt", "w");
	for (int i = 0; i < 15; i++)
	{
		scanf("%d", &ret);
		fprintf(f, "%d ", ret);
	}
	fclose(f);
	return 0;
}
