class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};
        vector<vector<int>> res;
        int min = intervals[0][0], max = intervals[0][1];
        if(newInterval[1] < min){
            res.push_back({newInterval[0], newInterval[1]});
            for(int i=0; i<n; i++)
                res.push_back({intervals[i][0], intervals[i][1]});
            sort(res.begin(), res.end());
            return res;
        }
        else if(newInterval[1] >= min && newInterval[1] <= max){
            res.push_back({std::min(newInterval[0], min), max});
            for(int i=1; i<n; i++)
                res.push_back({intervals[i][0], intervals[i][1]});
            sort(res.begin(), res.end());
            return res;
        }
        else{
            int i=0;
            while(i < n && newInterval[0] >= intervals[i][0]){
                i++;
            }
            int j=0;
            while(j < n && newInterval[1] >= intervals[j][0]){
                j++;
            }
            int mergeLeft, mergeRight;
            if(i == 0){
                mergeLeft = newInterval[0];
            }
            else if(intervals[i-1][1] < newInterval[0]){
                mergeLeft = newInterval[0];
                for(int x=0; x<i; x++)
                    res.push_back({intervals[x][0], intervals[x][1]});
            }
            else{
                mergeLeft = intervals[i-1][0];
                for(int x=0; x<i-1; x++)
                    res.push_back({intervals[x][0], intervals[x][1]});
            }
            if(intervals[j-1][1] < newInterval[1]){
                mergeRight = newInterval[1];
                for(int y=j; y<n; y++)
                    res.push_back({intervals[y][0], intervals[y][1]});
            }
            else{
                for(int y=j; y<n; y++)
                    res.push_back({intervals[y][0], intervals[y][1]});
                mergeRight = intervals[j-1][1];
            }
            
            res.push_back({mergeLeft, mergeRight});
            sort(res.begin(), res.end());
            return res;
        }
    }
};
