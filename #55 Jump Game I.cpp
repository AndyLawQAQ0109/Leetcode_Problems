class Solution {
    int n;
public:
    bool canJump(vector<int>& nums) {
        n = nums.size();
        int maxVal = 0;
        for(int i=0; i<n; i++){
            if(i > maxVal)
                return false;
            maxVal = (i + nums[i] > maxVal) ? i + nums[i] : maxVal;
        }
        return true;
    }
};
