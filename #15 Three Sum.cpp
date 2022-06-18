class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<nums.size() - 2; i++){
            if(nums[i] > 0) return res;
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    res.push_back({nums[i], nums[l], nums[r]});                    
                    while(l < r && nums[l] == nums[l+1])
                        l++;
                    while(l < r && nums[r] == nums[r-1])
                        r--;    
                    l++;
                    r--;                
                }
                else if(nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else
                    r--;
            }
            while(i < nums.size() - 1 && nums[i+1] == nums[i])
                i++;
        }
        return res;
    }
};
