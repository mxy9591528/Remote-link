//#include<iostream>
//using namespace std;
////����
////ȫ���еݹ��㷨
//void Perm(int list[], int k, int m)
//{
//	//list ���������е�����K��ʾ�� ����ڼ�������m��ʾ����ĳ���
//	if (k == m)
//	{
//		//K==m ��ʾ�������һ�����������ٽ��������յ����е�����Ҫ�����
//		for (int i = 0; i <= m; i++)
//			cout << list[i];
//		cout << endl;
//	}
//	else {
//		for (int i = k; i <= m; i++)
//		{
//			swap(list[i], list[k]);
//			Perm(list, k + 1, m);
//			swap(list[i], list[k]);
//		}
//	}
//
//}
//int main(void)
//{
//	int a[] = { 1,2,3 };
//	int m = 2;
//	Perm(a, 0, 2);
//}

//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//	const double l1 = 0.4463, l2 = 0.4663, l3 = 0.5663;
//	double sum;
//	int n;
//	cin >> n;
//	if (n <= 150)
//		sum = n * l1;
//	else if (n <= 400)
//		sum = 150 * l1 + (n - 150)*l2;
//	else
//		sum = 150 * l1 + 250 * l2 + (n - 400)*l3;
//	cout <<fixed<< setprecision(1) << sum;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string a;
//	getline(cin, a);
//	int len = a.length();
//	int k = len - 1;
//	for (int i = len-1; i>=0; i--)
//	{
//		if (i == 0)
//		{
//			for(int j=0;j<=k;j++)
//				cout << a[j];
//			cout << " ";
//		}
//		if (a[i] == ' ')
//		{
//			for (int j = i+1; j <= k; j++)
//				cout << a[j];
//			cout << " ";
//			k = i-1;
//		}
//	}
//	return 0;
//}