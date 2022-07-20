class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sz1 = s1.length(), sz2 = s2.length();
        int dp[sz1+1][sz2+1];
        dp[sz1][sz2] = 0;
        
        for(int i=sz1-1; i>=0; i--)
            dp[i][sz2] = dp[i+1][sz2] + s1[i];       
        for(int j=sz2-1; j>=0; j--)
            dp[sz1][j] = dp[sz1][j+1] + s2[j];

        for(int i=sz1-1; i>=0; i--){
            for(int j=sz2-1; j>=0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }   
                else{
                    dp[i][j] = min(dp[i+1][j] + s1[i], dp[i][j+1] + s2[j]);
                }
            }
        }

        return dp[0][0];
    }
};
