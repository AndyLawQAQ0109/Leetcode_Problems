class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums[0];
        nums.erase(nums.begin());
        return recurr(n, nums);
    }
    vector<vector<int>> recurr(int n, vector<int>& nums){
        if(nums.size() == 0)
            return {{}, {n}};
        
        vector<vector<int>> res = {{}, {nums[0]}};
        nums.erase(nums.begin());
        vector<vector<int>> prev = recurr(n_, nums);
        for(int i=1; i<prev.size(); i++){
            vector<int> tmp = prev[i];
            res.push_back(tmp);
            tmp.insert(tmp.begin(), n);
            res.push_back(tmp);
        }
        return res;
    }
};
