#include<stdio.h>
void Print1(int (*a)[6])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
			printf("%d,", a[i][j]);
		printf("\n");
	}
}
void Print2(int (*a)[5][6])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
			printf("%d,", *a[i][j]);
		printf("\n");
	}
}
int main()
{
	int a[5][6];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j <= 6; j++)
			a[i][j - 1] = j + 10 * i;
	}
	Print1(a);
	Print2(&a);
	return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
	long long n;
	while (~scanf("%lld", &n))
	{
		if (n % 2 == 0)
			continue;
		long long i = 1, ret = 1, sum = 0;
		while (ret <= n * n)
		{
			sum += ret;
			i++;
			ret += 8 * (i - 1);
		}
		if(sum<=pow(2,63)-1)
			printf("%lld\n",sum);
	}
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int*c, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int flag = 1;
		for (int j = 1; j < n - i; ++j)
		{
			if (c[j - 1]> c[j])
			{
			    int ret = c[j - 1];
				c[j - 1] = c[j];
				c[j] = ret;
				flag = 0;
			}
		}
		if (flag)//未交换直接返回
			return;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	BubbleSort(a, n);
	int d = a[1] - a[0];
	for (int i = 0; i < n-1; i++)
	{
		if (a[i + 1] - a[i] != d)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

void sort(int *a, int len)
{
	int i;
	int j;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int i = 0;
	int len;
	int temp;
	int a[100];

	FILE *fp;
	fp = fopen("1.txt", "r");
	if (fp == NULL)
	{
		perror("fopen");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		a[i] = temp;
		i++;
	}
	fclose(fp);

	sort(a, i - 1);
	len = i - 1;

	fp = fopen("2.txt", "w+");
	if (fp == NULL)
	{
		perror("fopen2:");
		exit(1);
	}

	for (i = 0; i <=len; i++)
	{
		fprintf(fp, "%d ", a[i]);
	}
	fclose(fp);
	return 0;
}


#include<stdio.h>
int main()
{
	int a = 3, b = 4;

	a = a - b;

	{

		int b = 2;

		a = a - b;

		b = a + b;

		printf("%d %d ", a, b);

	}

	printf("%d %d", a, b);

	return 0;
}

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
	fp = fopen("ouut.txt", "w+");
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
	printf("姓名:%s,性别:%s,生日:%d年%d月%d日,住址:%s", node1.name, node1.sex, node1.birthday.year, node1.birthday.month, node1.birthday.data, node1.address);

}
