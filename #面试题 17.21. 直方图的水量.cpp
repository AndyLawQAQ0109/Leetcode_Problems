class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size < 3)
            return 0;
        int area = 0;
        int maxHeights = *max_element(height.begin(), height.end());
        int blockArea = 0;
        for(int h=1; h<=maxHeights; h++){
            int l = 0, r = size - 1;
            while(l <= r && height[l] < h)
                l++;
            while(l <= r && height[r] < h)
                r--;
            blockArea += r - l + 1;
        }
        for(int i=0; i<size; i++)
            blockArea -= height[i];
        return blockArea;
    }
};
