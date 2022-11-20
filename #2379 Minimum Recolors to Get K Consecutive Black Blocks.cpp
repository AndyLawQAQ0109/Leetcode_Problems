class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int len = blocks.size();
        int result = 0;
        for(int i=0; i<k; i++)
            if(blocks[i] == 'W')
                result++;
        
        int ans = result;
        for(int i=1; i<=len - k; i++){
            if(blocks[i-1] == 'W')
                result--;
            if(blocks[i+k-1] == 'W')
                result++;
            ans = min(ans, result);
        }
        return ans;
    }
};
