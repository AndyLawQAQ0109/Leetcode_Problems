class Solution {
    vector<bool> visited;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        visited = vector<bool>(nums.size(), false);
        vector<vector<int>> res;
        vector<int> partial;
        backtrace(nums, 0, res, partial);
        return res;
    }
    void backtrace(vector<int> &nums, int idx, vector<vector<int>> &res, vector<int> partial){
        if(idx == nums.size()){
            res.push_back(partial);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(visited[i] || (i >= 1 && nums[i] == nums[i-1] && !visited[i-1]))
                continue;
            visited[i] = true;
            partial.push_back(nums[i]);
            backtrace(nums, idx + 1, res, partial);
            visited[i] = false;
            partial.pop_back();
        }
    }
};
