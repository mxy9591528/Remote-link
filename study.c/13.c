//21011111 ������
#include<stdio.h>
#include<Windows.h>
int main()
{
	int dB_mxy;
	printf("������ֱ���ֵ:\n");
	scanf("%d",&dB_mxy);
	if(dB_mxy<=50)
		printf("����\n");
	else if(dB_mxy<=70)
		printf("���֣�������\n");
	else if(dB_mxy<=90)
		printf("�ܳ�����ϸ���ܵ��ƻ�\n");
	else if(dB_mxy<=100)
		printf("���ּӾ磬��������\n");
	else if(dB_mxy<=120)
		printf("�������ܣ���һ���Ӽ���ʱ����\n");
	else
		printf("��������ȫ��\n");
	system("pause");
	return 0;
}