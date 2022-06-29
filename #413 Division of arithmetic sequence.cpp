class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int l = 0, r = 1;
        int count = 1;
        int diff = nums[r] - nums[l];
        int res = 0;
        while(r < n){
            if(nums[r] - nums[r-1] == diff){
                count++;
                r++;
            }
            else{
                l = r - 1;
                res += (count - 2) * (count - 1) / 2;
                count = 1;
                diff = nums[r] - nums[l];
            }
            if(r == n && count >= 3)
                res += (count - 2) * (count - 1) / 2;
        }
        return res;
    }
};
