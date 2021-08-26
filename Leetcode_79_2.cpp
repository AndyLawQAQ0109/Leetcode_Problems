class Solution {
private:
    string word_;
    int len_;
    vector<vector<int>> copy;
    vector<char> str;
public:
    void init_(int len_r, int len_c){
        copy = vector<vector<int>>(len_r, vector<int>(len_c));
        for(int i=0;i<len_r;i++){
            for(int j=0;j<len_c;j++)
                copy[i][j] = 1;
        }
        str = vector<char>();
    }
    bool exist(vector<vector<char>>& board, string word) {
        word_ = word;
        len_ = word.length();

        if(board.size()==0) 
            return false;
        int len_r = board.size();
        int len_c = board[0].size();

        init_(len_r,len_c);

        for(int i=0;i<len_r;i++){
            for(int j=0;j<len_c;j++){
                if(check(board, i, j, 0, word)) 
                    return true;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, int x, int y, int curr_len, string word){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;
        if(copy[x][y] == 0)
            return false;

        if(curr_len == len_ - 1){
            if(word[curr_len] == board[x][y])
                return true;
            else
                copy[x][y] = 1;
        }
        else{
            if(word[curr_len] == board[x][y]){
                if(copy[x][y] == 1){
                    bool l, r, u, d;  
              
                    // char cur = board[x][y];
                    // board[x][y] = 0;
                    copy[x][y] = 0;
                    l = check(board, x, y-1, curr_len+1, word);
                    r = check(board, x, y+1, curr_len+1, word);
                    u = check(board, x-1, y, curr_len+1, word); 
                    d = check(board, x+1, y, curr_len+1, word); 
                    copy[x][y] = 1;
                    // board[x][y] = cur; 
                    return l || r || u || d;
                }
            }
            
        }
        // copy[x][y] = 1;
        return false;           
    }
};
