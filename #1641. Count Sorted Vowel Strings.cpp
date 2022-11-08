class Solution {
public:
    //      a   e   i   o   u
    // n=1  1   1   1   1   1
    // n=2  5   4   3   2   1
    // n=3  15  10  6   3   1
    int countVowelStrings(int n) {
        if(n == 1)
            return 5;
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for(int j=2; j<=n; j++){
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
        }
        return a + e + i + o + u;
    }
    
};
