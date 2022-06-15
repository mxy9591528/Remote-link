#include<stdio.h>
int main()
{
	char a[30], b[30];
	int i, n, m;
	printf("ÇëÊäÈë×Ö·û´®:\n");
	gets(a);
	printf("ÇëÊäÈë·¶Î§:\n");
	scanf("%d %d", &n, &m);
	for (i = n; i <= m; i++)
		b[i - n] = a[i];
	b[i - n + 1] = '\0';
	printf("%s", b);
	return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
	char a[6][20], b[6][20];
	int i, j;
	printf("ÇëÊäÈëÁù¸ö×Ö·û´®:\n");
	for (i = 0; i < 6; i++)
	{
		gets(a[i]);
		strcpy(b[i], a[i]);
	}
	printf("\n");
	for (i = 0; i < 6; i++)
		printf("%s\n", a[i]);
		printf("\n");
	for (i = 0; i < 6; i++)
	{
		int min = i;
		for (j = i + 1; j < 6; j++)
			if (strcmp(b[min], b[j]) > 0)
				min = j;
		if (min != i)
		{
			char temp[20];
			strcpy(temp, b[min]);
			strcpy(b[min], b[i]);
			strcpy(b[i], temp);
		}
	}
	for (i = 0; i < 6; i++)
		printf("%s\n", b[i]);
}

