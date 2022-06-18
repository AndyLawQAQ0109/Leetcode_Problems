class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int len1 = firstList.size(), len2 = secondList.size();
        if(len1 == 0 || len2 == 0) return {};

        vector<vector<int>> res;
        int l = 0, r = 0;
        while(l < len1 && r < len2){
            int left = max(firstList[l][0], secondList[r][0]);
            int right = min(firstList[l][1], secondList[r][1]);
            if(left <= right)
                res.push_back({left, right});            
            if(firstList[l][1] == secondList[r][1]){
                l++;
                r++;
            }
            else if(firstList[l][1] < secondList[r][1])
                l++;
            else
                r++;
        }
        return res;
    }
};
