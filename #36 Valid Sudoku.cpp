class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> row[9], column[9], gird[9]; 
        int i = 0, j = 0;
        for(int i=0; i < 9; i++){           
            for(int j=0; j < 9; j++){
                char c = board[i][j];
                if(board[i][j] != '.'){                   
                    if(row[i][c] || column[j][c]|| gird[(i / 3) * 3 + j / 3][c])
                        return false;

                    row[i][c]++;
                    column[j][c]++;
                    gird[(i / 3) * 3 + j / 3][c]++;
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};
        int column[9][10] = {0};
        int grid[9][10] = {0};
        for(int i=0; i < 9; i++){           
            for(int j=0; j < 9; j++){
                int c = board[i][j] - '0';
                if(board[i][j] != '.'){                   
                    if(row[i][c] || column[j][c] || grid[(i/3)*3+j/3][c])
                        return false;

                    row[i][c] = 1;
                    column[j][c] = 1;
                    grid[(i/3)*3+j/3][c] = 1;
                }
            }
        }

        return true;
    }
};
