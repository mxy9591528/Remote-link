//21011111 ������
#include<stdio.h>
#include<windows.h>
int main()
{
	double s_mxy=0;
	int i=0;
	while(++i<=100)
	{
		s_mxy+=1.0/i;
	}
	printf("��������%lf\n",s_mxy);
	system("pause");
	return 0;
}