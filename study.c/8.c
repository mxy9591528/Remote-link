//21011111 马县杨
#include<stdio.h>
#include<Windows.h>
int main()
{
	int n_mxy,sum=0;
	printf("请输入数字:\n");
	scanf("%d",&n_mxy);
	while(n_mxy)
	{
		sum+=n_mxy%10;
		n_mxy/=10;
	}
	printf("数位数字之和是:%d\n",sum);
	system("pause");
	return 0;
}