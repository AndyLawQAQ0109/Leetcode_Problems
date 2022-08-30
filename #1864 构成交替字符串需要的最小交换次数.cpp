class Solution {
public:
    int minSwaps(string s) {
        unordered_map<char, int> cnt;
        for(char c: s)
            cnt[c]++;
        int diff = cnt['0'] - cnt['1'];
        if(diff > 1 || diff < -1)
            return -1;
        
        string refStr = "";
        string refStr2 = "";
        if(diff == 1){ // "0101..."
            for(int i=0; i<cnt['1']; i++)
                refStr += "01";
            refStr += "0";
        }
        else if(diff == -1){ // "1010..."
            for(int i=0; i<cnt['0']; i++)
                refStr += "10";
            refStr += "1";
        }
        else{ // both are ok
            for(int i=0; i<cnt['0']; i++)
                refStr += "01";
            refStr += "0";

            for(int i=0; i<cnt['0']; i++)
                refStr2 += "10";
            refStr2 += "1";
        }
        int res = 0;
        for(int i=0; i<s.size(); i++)
            if(s[i] != refStr[i])
                res++;
        int res2 = 0;
        if(!refStr2.empty()){
            for(int i=0; i<s.size(); i++)
                if(s[i] != refStr2[i])
                    res2++;
            return min(res, res2) / 2;
        }
        return res / 2;
    }
};
