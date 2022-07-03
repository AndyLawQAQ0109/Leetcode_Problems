class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            dp[i] = 1;
            res = 1;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i])
                    res = max(res, dp[j] + 1);
            }
            // cout<<res<<"\t";
            dp[i] = res;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
