#file 
#include<stdio.h>
void set_odd(int*array, int size)
{
	int i, count = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] % 2 == 0)
		{
			count++;
			--array[i];
		}
	}
	printf("%d\n", count);
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
}

#include<stdio.h>
int main()
{
	FILE*fin = fopen("in.txt", "r");
	FILE*fout = fopen("out.txt", "W");
	if (!fin || !fout)
	{
		printf("error\n");
		return 1;
	}
	char c;
	while ((c = fgetc(fin)) != EOF)
	{
		if (c != ',')
			fprintf(fout, "%c ", c);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

#include<stdio.h>
int main()
{
	FILE*in = fopen("input.csv", "r");
	FILE*out = fopen("output.csv", "w");
	int sum = 0, ret[5], i;
	while (!feof(in))
	{
		fscanf(in, "%d,%d,%d,%d,%d\n", &ret[0], &ret[1], &ret[2], &ret[3], &ret[4]);
		for (i = 0; i < 5; i++)
			sum += ret[i];
		fprintf(out, "%d,%d,%d,%d,%d,%d\n", ret[0], ret[1], ret[2], ret[3], ret[4], sum);
		sum = 0;
	}
	fclose(in);
	fclose(out);
	return 0;
}


#include<stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	getchar();
	char c[1024];
	gets(c);
	for (i = 0; c[i]; i++)
	{
		if (c[i] + n > 126)
			c[i] = c[i] + n - 127 + 22;
		printf("%c", c[i] + n);
	}
	return 0;
}
