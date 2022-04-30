//21011111 马县杨
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
	printf("请输入数字:\n");
	scanf("%d",&n_mxy);
	if(Judge(n_mxy))
		printf("%d能被6、9、14整除\n",n_mxy);
	else
		printf("%d不能被6、9、14整除\n",n_mxy);
	system("pause");
	return 0;
}