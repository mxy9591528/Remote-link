////������
//#include<iostream>
//using namespace std;
//#define N 10
//int main()
//{
//	int a[N][N], n;
//	cout << "���������n" << endl;
//	cin >> n;
//	for (int i = 0; i < n; i++) 
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//		for (int j = 1; j < i; j++)
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];	
//	}
//	for (int i = 0; i < n; i++) 
//	{
//		for (int j = 1; j <= n - 1 - i; j++)		
//			cout << " ";
//		for (int j = 0; j <= i; j++)			
//			cout << a[i][j] << " ";
//		cout << endl;
//	}
//	return 0;
//}

////������
//#include<iostream>
//using namespace std;
//int main()
//{
//	long long n, t = 1;
//	int s = 0;
//	cout << "����������:" << endl;
//	cin >> n;
//	while (n)
//	{
//		s += n % 10;
//		t *= n % 10;
//		n /= 10;
//	}
//	cout << "��λ֮��s=" << s << endl << "��λ֮��t=" << t << endl;
//	return 0;
//}

////������
//#include<iostream>
//#define N 4
//#define M 5
//using namespace std;
//int main()
//{
//	int a[N][M], sum = 0;
//	cout << "���������ֵ:" << endl;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> a[i][j];
//			if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
//				sum += a[i][j];
//		}
//	}
//	cout << "��������֮��Ϊ:" << sum << endl;
//	return 0;
//}
