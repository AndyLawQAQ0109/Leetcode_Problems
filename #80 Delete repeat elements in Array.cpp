class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int l = 0, r = 2;
        while(l < r && r < nums.size()){
            if(nums[l] != nums[r]){
                l++;
                r++;
                continue;
            }
            while(r < nums.size() && nums[l] == nums[r]){
                nums.erase(nums.begin()+r);
            }
            l = r;
            r += 2;
        }
        return nums.size();
    }
};
// 0 ms
/*
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
*/
