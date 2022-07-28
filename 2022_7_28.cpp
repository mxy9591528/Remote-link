class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //初始化dp为最小
        vector<vector<int> > dp(n, vector<int>(5, -10000)); 
        //第0天不持有状态
        dp[0][0] = 0; 
        //第0天持有股票
        dp[0][1] = -prices[0]; 
        //状态转移
        for(int i = 1; i < n; i++){ 
            dp[i][0] = dp[i - 1][0]; 
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        //选取最大值，可以只操作一次
        return max(dp[n - 1][2], max(0, dp[n - 1][4])); 
    }
};

