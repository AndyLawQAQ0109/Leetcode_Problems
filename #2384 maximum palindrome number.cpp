class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.size();
        int nums[10] = {0};
        for(char c: num)
            nums[c - '0']++;
        
        string left;
        for(int i=9; i>=0; i--){
            if(i == 0 && left.empty())
                break;
            for(int j=0; j<nums[i]/2; j++)
                left.push_back(i + '0');
            nums[i] %= 2;
        }        
        string right = left;
        reverse(right.begin(), right.end());
        for(int i=9; i>=0; i--){
            if(nums[i] > 0){
                left.push_back(i + '0');
                break;
            }
        }
        return left + right;
    }
};
