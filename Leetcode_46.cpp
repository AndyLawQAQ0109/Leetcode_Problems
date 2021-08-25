class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans = vector<vector<int>>();
        if(len == 1){
            vector<int> ele;
            ele.push_back(nums[0]);
            ans.push_back(ele);

            return ans;
        }
        else{
            vector<int> prev_ints;
            recur(nums, prev_ints, len, ans);
        }
        return ans;
    }
    // len is
    void recur(vector<int> nums, vector<int>& prev_ints, int len, vector<vector<int>>& ans){
        if(len == 2){
            vector<int> ele1, ele2;
            for(int i=0;i<prev_ints.size();i++){
                ele1.push_back(prev_ints[i]);
                ele2.push_back(prev_ints[i]);
            }
            
            ele1.push_back(nums[0]); ele1.push_back(nums[1]);
            ele2.push_back(nums[1]); ele2.push_back(nums[0]);
            ans.push_back(ele1);
            ans.push_back(ele2);
        }
        else{
            for(int i=0;i<len;i++){
                int additional_ = nums[i];
                vector<int> local = prev_ints;
                local.push_back(additional_);

                vector<int> nums_ = vector<int>();
                for(int j=0;j<len;j++){
                    if(i != j)
                        nums_.push_back(nums[j]);
                }
                recur(nums_, local, len-1, ans);
            }
        }
    }
};