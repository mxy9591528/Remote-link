//21011111 ������
#include<stdio.h>
#include<Windows.h>
int Judge(int n)
{
	if(n%6&&n%9&&n%14)
		return 0;
	else
		return 1;
}
int main()
{
	int n_mxy;
	printf("����������:\n");
	scanf("%d",&n_mxy);
	if(Judge(n_mxy))
		printf("%d�ܱ�6��9��14����\n",n_mxy);
	else
		printf("%d���ܱ�6��9��14����\n",n_mxy);
	system("pause");
	return 0;
}