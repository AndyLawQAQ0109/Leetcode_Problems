class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        int min = intervals[0][0], max = intervals[0][1];
        vector<vector<int>> res;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= min && intervals[i][0] <= max)
                max = std::max(max, intervals[i][1]);
            else if(intervals[i][0] < min){
                min = intervals[i][0];
                max = std::max(max, intervals[i][1]);
            }
            else{
                res.push_back({min, max});
                min = intervals[i][0];
                max = intervals[i][1];
            }
            if(i == intervals.size() - 1)
                res.push_back({min, max});
        }
        return res;
    }
};
