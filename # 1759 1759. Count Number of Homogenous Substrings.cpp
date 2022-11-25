class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1E9 + 7;
        long long res = 1;
        int i = 1;
        
        char currChar = s[0];
        int last = 1;
        while(i < s.size()){
            if(s[i] != currChar){
                last = 1;
                currChar = s[i];
            }
            else
                last++;
            
            res = (res + last) % mod;
            i++;
            
        }
        return res;
    }
};
