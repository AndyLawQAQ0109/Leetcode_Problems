class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = nums;
        for(int i = dp.size() - 2; i >= 0 ; i--){
            if (dp[i] < dp[i] + dp[i + 1])
                dp[i] = dp[i] + dp[i + 1];
        }
        return *std::max_element(std::begin(dp), std::end(dp));
    }
};
