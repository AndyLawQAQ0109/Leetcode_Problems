// Copy Paste
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int l = 0, r = 0;
        int count = 0;

        int mult = 1;
        while(r < nums.size()){
            mult *= nums[r];
            while(mult >= k){
                mult /= nums[l];
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
};

