class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int r = bsRow(matrix, target, 0, m-1);
        if(r == -1) return false;
        if(r == m - 1 && target > matrix[r][n-1]) return false;
        return bsCol(matrix[r], target, 0, n-1);
    }
    int bsRow(vector<vector<int>>& matrix, int target, int s, int e){
        if(s == e){
            if(target >= matrix[s][0]) return s;
            return s - 1;
        }
        int mid = (s + e) / 2;
        if(target == matrix[mid][0])
            return mid;
        if(target < matrix[mid][0])
            return bsRow(matrix, target, s, mid);
        if(target > matrix[mid][0])
            return bsRow(matrix, target, mid+1, e);
        return -1;
    }
    bool bsCol(vector<int>& matrix, int target, int s, int e){
        if(s == e) return target == matrix[s];
        int mid = (s + e) / 2;
        if(target == matrix[mid]) return true;
        if(target < matrix[mid]) return bsCol(matrix, target, s, mid);
        return bsCol(matrix, target, mid+1, e);
    }
};

// Calculate Index
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        return bs(matrix, 0, 0, m-1, n-1, target);
    }
    bool bs(vector<vector<int>>& matrix, int sx, int sy, int ex, int ey, int target){
        if(sx == ex && sy == ey) return target == matrix[sx][sy];

        int m = matrix.size();
        int n = matrix[0].size();
        int num = (n - sy) + (ey + 1) + (ex - sx - 1) * n - 1;
        num = (sx * n + sy) + num / 2;
        int xmid = num / n;
        int ymid = num % n;

        if(target == matrix[xmid][ymid]) return true;
        if(target < matrix[xmid][ymid]) return bs(matrix, sx, sy, xmid, ymid, target);
        else{
            if(ymid < matrix[0].size() - 1)
                return bs(matrix, xmid, ymid+1, ex, ey, target);
            else
                return bs(matrix, xmid+1, 0, ex, ey, target);
        } 
    }

};
