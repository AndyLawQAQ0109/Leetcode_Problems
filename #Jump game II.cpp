class Solution {
    int n;
public:
    int jump(vector<int>& nums) {
        n = nums.size();
        if(n == 1) 
            return 0;
        vector<int> dp(n, 0);
        for(int idx=0; idx<n; idx++){        
            for(int i=idx + 1; i<=idx + nums[idx]; i++){
                if(dp[i] == 0)
                    dp[i] = dp[idx] + 1;
                else
                    dp[i] = min(dp[idx] + 1, dp[i]);
                if(dp[n-1] != 0)
                    return dp[n-1];
            }
        }
        return dp[n-1];
    }
};
