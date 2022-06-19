class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 1)
            return (nums[0] >= target) ? 1 : 0;
        
        int l = 0, r = 0;
        int total = 0;
        int res = INT_MAX;
        while(r < nums.size()){            
            total += nums[r];
            
            if(total >= target){
                res = (r - l + 1) < res ? (r - l + 1) : res;
                while(l < r && total >= target){
                    total -= nums[l++];
                    if(total >= target && r - l + 1 < res)
                        res = r - l + 1;
                }
            }
            r++;           
        }
        if(res < INT_MAX)
            return res;
        return 0;
    }
};


// Shorter
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {      
        int l = 0, r = 0;
        int total = 0;
        int res = INT_MAX;

        while(r < nums.size()){        
            total += nums[r];            
            while(total >= target){
                res = (r - l + 1) < res ? (r - l + 1) : res;
                total -= nums[l];
                l++;
            }
            r++;           
        }
        if(res < INT_MAX)
            return res;
        return 0;
    }
};
