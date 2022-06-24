class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> partial;
        backtrace(candidates,target, 0, partial, res);
        return res;
    }
    void backtrace(vector<int> &candidates, int target, int begin, vector<int> &partial, vector<vector<int>> &res){
        if(target < 0)
            return;
        if(target == 0){
            res.push_back(partial);
            return;
        }
        for(int i=begin; i<candidates.size(); i++){
            partial.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i, partial, res);
            partial.pop_back();
        }
    }
};
