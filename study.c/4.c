//21011111 ������
#include<stdio.h>
#include<windows.h>
int main()
{
	double lenth_mxy,width,x;
	printf("��������β�ƺ�ĳ��Ϳ��Լ��޼���ƺ���ٶ�x:\n");
	scanf("%lf %lf %lf",&lenth_mxy,&width,&x);
	printf("�޼���ƺ����ʱ��Ϊ��%lf\n",lenth_mxy*width/x);
	system("pause");
	return 0;
}