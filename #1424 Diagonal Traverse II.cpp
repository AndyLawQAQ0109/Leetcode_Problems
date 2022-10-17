class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int rows = nums.size();
        int maxLen = 0;
        for(int i=0; i<rows; i++)
            maxLen = nums[i].size() > maxLen ? nums[i].size() : maxLen;
        
//         vector<vector<int>> matrix(rows, vector<int>(maxLen, 0));
//         for(int i=0; i<rows; i++){
//             for(int j=0; j<maxLen; j++){
//                 if(j < nums[i].size())
//                     matrix[i][j] = nums[i][j];
//             }
//         }
        
//         for(int i=0; i<rows; i++){
//             res.push_back(matrix[i][0]);
//             int x = i-1, y = 1;
//             while(x >= 0 && y < maxLen){
//                 if(matrix[x][y] != 0)
//                     res.push_back(matrix[x][y]);
//                 x--;
//                 y++;
//             }
//         }
//         for(int i=1; i<matrix[rows-1].size(); i++){
//             if(matrix[rows-1][i] != 0)
//                 res.push_back(matrix[rows-1][i]);
//             int x = rows - 2, y = i + 1;
//             while(x >= 0 && y < maxLen){
//                 if(matrix[x][y] != 0)
//                     res.push_back(matrix[x][y]);
//                 x--;
//                 y++;
//             }

//         }
        
        unordered_map<int, vector<int>> m;
        for(int i=0; i<rows; i++){
            for(int j=0; j<nums[i].size(); j++){
                int sum = i + j;
                m[sum].push_back(nums[i][j]);
            }
        }
        
        for(int i=0; i<rows-1+maxLen; i++){
            for(int j=m[i].size()-1; j>=0; j--)
                res.push_back(m[i][j]);
        }
        
        return res;
    }
};
