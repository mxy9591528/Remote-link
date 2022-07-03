#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, sumt = 0;
	cin >> n;
	int**p = new int*[2];
	for (int i = 0; i < 2; i++)
		p[i] = new int[n];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int j = i + 1;
		while (j < n)
		{
			int t = p[0][i] + p[1][i] - p[0][j];
			if (t > 0)
				sumt += t;
			else
				break;
			j++;
		}
	}
	cout << sumt << endl;
}