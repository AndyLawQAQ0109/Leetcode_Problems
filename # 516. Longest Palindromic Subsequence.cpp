class Solution {
public:
    // Bottom-Up DP
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for(int i=size-1; i>=0; i--){
            dp[i][i] = 1;
            for(int j=i+1; j<size; j++){
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][size-1];
    }
    
};
// Top-Down DP
// class Solution {
// public:
//     int arr[1000][1000] = {};
//     int longestPalindromeSubseq(string s) {
//         return dp(s, 0, s.size() - 1);
//     }
//     int dp(string &s, int l, int r){
//         if(l > r) return 0;
//         if(l == r) return 1;
//         if(arr[l][r] != 0)
//             return arr[l][r];
//         if(s[l] == s[r]){
//             arr[l][r] = dp(s, l+1, r-1) + 2;
//             return arr[l][r];
//         }
//         arr[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
//         return arr[l][r];
//     }
// };
