class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // Because there exists negative, minimum number(neg num) might become maximum number(max num)
        // Therefore, we have to maintain min value as well.
        vector<int> dpmin(n, 0);
        vector<int> dpmax(n, 0);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        
        for(int i=1; i<n; i++){
            dpmin[i] = min(nums[i], min(nums[i] * dpmin[i-1], nums[i] * dpmax[i-1]));
            dpmax[i] = max(nums[i], max(nums[i] * dpmin[i-1], nums[i] * dpmax[i-1]));
        }
        return *max_element(dpmax.begin(), dpmax.end());
    }
};
