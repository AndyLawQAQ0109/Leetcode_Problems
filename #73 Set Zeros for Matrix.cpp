class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r_flag = false, c_flag = false;
        int row = matrix.size();
        int col = matrix[0].size();

        // Check 1st row
        for(int i=0; i<col; i++){
            if(matrix[0][i] == 0) r_flag = true;
        }
        // Check 1st column
        for(int i=0; i<row; i++){
            if(matrix[i][0] == 0) c_flag = true;
        }

        // Use 1st row & line record position
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Find 1st row's 0 & update its column
        for(int i=1; i<col; i++){
            if(matrix[0][i] == 0){
                for(int j=1; j<row; j++)
                    matrix[j][i] = 0;
            }
            
        }

        // Find 1st column's 0 & update its row
        for(int i=1; i<row; i++){
            if(matrix[i][0] == 0){
                for(int j=1; j<col; j++)
                    matrix[i][j] = 0;
            }
        }

        // Update 1st row & column
        if(c_flag){
            for(int i=0; i<row; i++)
                matrix[i][0] = 0;
        }
        if(r_flag){
            for(int i=0; i<col; i++)
                matrix[0][i] = 0;
        }
    }
};
