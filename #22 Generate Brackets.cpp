class Solution {
    int num;
public:
    vector<string> generateParenthesis(int n) {
        num = n;
        vector<string> res;
        string partial = "";
        trace(res, partial, n, n);
        return res;
    }
    void trace(vector<string> &res, string partial, int l, int r){
        if(r < l) return;
        if(l == 0 && r == 0)
            res.push_back(partial);
        if(l > 0)
            trace(res, partial + "(", l - 1, r);
        if(r > 0)
            trace(res, partial + ")", l, r - 1);
    }
};
