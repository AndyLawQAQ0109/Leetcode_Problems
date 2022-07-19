class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return;
        if(n == 2){
            int tmp = matrix[0][n-1]; // tmp = 11
            matrix[0][n-1] = matrix[0][0]; // [0][n-1] = 5
            matrix[0][0] = tmp; // [0][0] = tmp(11)
            tmp = matrix[n-1][n-1]; // tmp = 16
            matrix[n-1][n-1] = matrix[0][0]; // [n-1][n-1] = 11
            matrix[0][0] = tmp; // [0][0] = tmp(16)
            tmp = matrix[n-1][0]; // tmp = 15
            matrix[n-1][0] = matrix[0][0]; // [n-1][0] = 16
            matrix[0][0] = tmp; // [0][0] = 15
            return;
        }
        for(int j=0; j<n-2; j++){
            for(int i=j; i<n-1-j; i++){
                int tmp = matrix[i][n-1-j]; // tmp = [1][n-1-1](8)
                matrix[i][n-1-j] = matrix[j][i]; // [1][n-1-1] = [1][1](4)
                matrix[j][i] = tmp; // [1][1] = 8
                tmp = matrix[n-1-j][n-1-i]; // tmp = [n-1-1][n-1-1](6)
                matrix[n-1-j][n-1-i] = matrix[j][i]; // [n-1-1][n-1-1] = [1][1](8)
                matrix[j][i] = tmp; // [1][1] = 6
                tmp = matrix[n-1-i][j]; // tmp = [n-1-1][1](3)
                matrix[n-1-i][j] = matrix[j][i]; // [n-1-1][1] = [1][1](6)
                matrix[j][i] = tmp; // [1][1] = 3
            }
        }
    }
};
