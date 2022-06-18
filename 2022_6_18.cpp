#include<iostream>
#include<vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int rob(vector<int>& nums) {
	// dp【i】=max（dp【i-1】，dp【i-2】+nums【i】）
	// dp【i】表示 nums【0~i】的最大偷法

	if (nums.empty())
		return 0;
	if (nums.size() == 1)
		return nums[0];

	vector<int> dp(nums.size());
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);

	for (int i = 2; i < nums.size(); ++i) {
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}

	return dp[nums.size() - 1];

}
int main()
{
	int n;
	cin >> n;
	vector<int>a(10);
	for (int i = 0; i < n; i++)
	{
		int ret;
		cin >> ret;
		a.push_back(ret);
	}
	int k = rob(a);
	cout << k;
}