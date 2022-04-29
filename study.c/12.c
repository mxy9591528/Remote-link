//21011111 马县杨
#include<stdio.h>
#include<Windows.h>
int Judge(int n)
{
	if(n==n%100)
		return 1;
	else
		return 0;
}
int main()
{
	int m_mxy;
	printf("请输入数字:\n");
	scanf("%d",&m_mxy);
	if(Judge(m_mxy))
		printf("%d是守形数\n",m_mxy);
	else
		printf("%d不是守形数\n",m_mxy);
	system("pause");
	return 0;
}