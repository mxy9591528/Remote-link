//21011111 ������
#include<stdio.h>
#include<Windows.h>
int main()
{
	double A1_mxy,B1,C1,A2,B2,C2,x,y;
	printf("������ϵ��������\n");
	scanf("%lf %lf %lf %lf %lf %lf",&A1_mxy,&B1,&C1,&A2,&B2,&C2);
	x=(C1*B2-C2*B1)/(A1_mxy*B2-A2*B1);
	y=(C1*A2-C2*A1_mxy)/(B1*A2-B2*A1_mxy);
	printf("��x=%lf,y=%lf\n",x,y);
	system("pause");
	return 0;
}