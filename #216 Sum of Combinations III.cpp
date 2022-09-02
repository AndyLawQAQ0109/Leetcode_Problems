class Solution {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> partial;
        reduceSize(partial, k, n, 0);
        return ans;
    }
    void reduceSize(vector<int> &partial, int k, int n, int start){
        if(n <= 0 || start > 8)
            return;
        if(k == 2){
            for(int i=start; i<9; i++){
                if(n - nums[i] > nums[i] && n - nums[i] < 10){
                    partial.push_back(nums[i]);
                    partial.push_back(n - nums[i]);
                    ans.push_back(partial);
                    partial.pop_back();
                    partial.pop_back();
                }
            }
        }
        else{
            for(int i=start; i<9; i++){
                partial.push_back(nums[i]);
                reduceSize(partial, k-1, n-nums[i], i+1);
                partial.pop_back();
            }
        }
    }
};
