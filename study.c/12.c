//21011111 ������
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
	printf("����������:\n");
	scanf("%d",&m_mxy);
	if(Judge(m_mxy))
		printf("%d��������\n",m_mxy);
	else
		printf("%d����������\n",m_mxy);
	system("pause");
	return 0;
}