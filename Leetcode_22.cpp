class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        recur("", n, n, ans);
        return ans;
    }
    void recur(string res, int left, int right, vector<string>& ans){
        if(left == 0 && right == 0){
            ans.push_back(res);
        }
        if(left > right)
            return;
        if(left != 0){
            recur(res+"(", left-1, right, ans);
        }
        if(right != 0){
            recur(res+")", left, right-1, ans);
        }
    }
};