//21011111 ������
#include<stdio.h>
#include<Windows.h>
int main()
{
	int n_mxy,sum=0;
	printf("����������:\n");
	scanf("%d",&n_mxy);
	while(n_mxy)
	{
		sum+=n_mxy%10;
		n_mxy/=10;
	}
	printf("��λ����֮����:%d\n",sum);
	system("pause");
	return 0;
}