//21011111 ������
#include<stdio.h>
#include<Windows.h>
int main()
{
	float B_mxy,S,P,T;
	printf("������������ʣ����»���Ӫҵ�Ӫҵ����ɵı�����\n");
	scanf("%f %f %f",&B_mxy,&S,&P);
	T=B_mxy+S*P;
	printf("ʵ������Ϊ��%f\n",T);
	system("pause");
	return 0;
}