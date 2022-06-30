class Solution {
public:
    int numDecodings(string s) {
        map<string, char> m; // number -> alphabet
        char c = 'A';
        for(int i=1; i<27; i++)
            m[to_string(i)] = c + i - 1;
        
        int size = s.size();
        if(size == 1)
            return s[0] == '0' ? 0 : 1;
        vector<int> dp(size, 0);
        if(s[0] == '0')
            return 0;
        dp[0] = 1;
        if((s[0] == '1' && s[1] >= '0' && s[1] <= '9') || (s[0] == '2' && s[1] >= '0' && s[1] <= '6')){
            if(s[1] != '0')
                dp[1] = 2;
            else
                dp[1] = 1;
        }
        else if(s[0] > '2' && s[1] == '0')
            return 0;
        else
            dp[1] = 1;
        for(int i=2; i<size; i++){
            if(s[i-1] == '0'){
                if(s[i] != '0')
                    dp[i] = dp[i-1];
                else
                    return 0;
            }
            else if(s[i-1] == '1' && (s[i] >= '0' && s[i] <= '9')){
                if(s[i] != '0')
                    dp[i] = dp[i-1] + dp[i-2];
                else
                    dp[i] = dp[i-2];
            }
            else if(s[i-1] == '2' && (s[i] >= '0' && s[i] <= '6')){
                if(s[i] != '0')
                    dp[i] = dp[i-1] + dp[i-2];
                else
                    dp[i] = dp[i-2];
            }
            else if(s[i] == '0')
                return 0;
            else
                dp[i] = dp[i-1];
        }

        return dp[size-1];
    }
};
