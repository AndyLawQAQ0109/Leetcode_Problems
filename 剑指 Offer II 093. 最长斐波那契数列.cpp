class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int size = arr.size();
        int ans = 0;
        unordered_map<int, int> indices;
        for(int i=0; i<size; i++)
            indices[arr[i]] = i;
        
        // dp[j][i] is the series ended with arr[j] & arr[i]
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int i=0; i<size; i++){
            // reduce # of iteration 
            // becase arr[j] * 2 <= arr[i] means arr[k] + arr[j] must less than arr[i] 
            for(int j=i-1; j>=0 && arr[j] * 2 > arr[i]; j--){ 
                int k = indices.count(arr[i] - arr[j]) ? indices[arr[i] - arr[j]] : -1;
                // dp[j][i]'s length is max(previous length + 1, 3)
                if(k >= 0 && k < j)
                    dp[j][i] = max(dp[k][j] + 1, 3);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
