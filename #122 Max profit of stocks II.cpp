class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] -> Max profit if no stock in hand at day i
        // dp[i][1] -> Max profit if has stock in hand at day i
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0; dp[0][1] = -prices[0];   
        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); // Not stock previously || Sold today (Have 1 stock before)
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]); // Keep previous stock || Buy today's stock (Have no stock before)
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};
// Method 2:
// Because there's no limit with # of transactions
// Sum up values of all increased trends
// ex. [1,2,3]: (2-1) + (3-2)
// ex. [7,1,5,3,6,4]: (5-1) + (6-3)
