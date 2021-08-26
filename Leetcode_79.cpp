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
        if(len_ == 1){
            return board[0][0] == word[0];
        }

        int len_r = board.size();
        int len_c = board[0].size();

        init_(len_r, len_c);

        if(len_c * len_r < len_)
            return false;

        char first_ch = word[0];
        vector<int> x, y;
        for(int i=0;i<len_r;i++){
            for(int j=0;j<len_c;j++){
                if(board[i][j] == first_ch){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        for(int index=0;index<x.size();index++){ // for each possible start letter
            str.push_back(board[x[index]][y[index]]);
            copy[x[index]][y[index]] = 0;
            // check each element's possible pathes
            if(check(board, first_ch, x[index], y[index]-1, word[1], 1)) return true; // L
            if(check(board, first_ch, x[index], y[index]+1, word[1], 1)) return true; // R
            if(check(board, first_ch, x[index]-1, y[index], word[1], 1)) return true; // U
            if(check(board, first_ch, x[index]+1, y[index], word[1], 1)) return true; // D
        }
        for(int i=0;i<copy.size();i++){
            for(int j=0;j<copy[0].size();j++)
                cout<<copy[i][j]<<" ";
            cout<<endl;
        }
        return false;
    }
    bool check(vector<vector<char>>& board, char curr_ch, int x, int y, char next_ch, int curr_len){
        int len_r = board.size();
        int len_c = board[0].size();

        // whether outof bound
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;

        if(copy[x][y]){ // able to check
            cout<<"Last: "<<curr_ch<<" "<<next_ch<<"\n";
            if(curr_len == len_ - 1){ 
                if(next_ch == board[x][y]){ // check last char
                    copy[x][y] = 0;
                    // str.push_back(curr_ch);
                    // str.push_back(next_ch);
                    return true;
                }
                return false;
            }
            else{
                if(next_ch == board[x][y]){
                    copy[x][y] = 0;
                    str.push_back(next_ch);
                    curr_ch = next_ch;
                    next_ch = word_[curr_len+1];
                    
                    if(y-1 >= 0 && y-1 < board[0].size()){
                        if(copy[x][y-1] != 0){
                            cout<<"L"<<endl;
                            if(check(board, curr_ch, x, y-1, next_ch, curr_len+1)) // L
                                return true; 
                            else
                                copy[x][y-1] = 1;
                        }
                    }
                    if(y+1 >= 0 && y+1 < board[0].size()){
                        if(copy[x][y+1] != 0){
                            cout<<"R"<<endl;
                            if(check(board, curr_ch, x, y+1, next_ch, curr_len+1)) // R
                                return true; 
                            else
                                copy[x][y+1] = 1;
                        }
                    }
                    if(x-1 >= 0 && x-1 < board.size()){
                        if(copy[x-1][y] != 0){
                            cout<<"U"<<endl;
                            if(check(board, curr_ch, x-1, y, next_ch, curr_len+1)) // U
                                return true;
                            else
                                copy[x-1][y] = 1;
                        }
                    }
                    if(x+1 >= 0 && x+1 < board.size()){
                        if(copy[x+1][y] != 0){
                            cout<<"D"<<endl;
                            if(check(board, curr_ch, x+1, y, next_ch, curr_len+1)) // D
                                return true;
                            else
                                copy[x+1][y] = 1;
                        }   
                    }
                    
                }
            }
        }
        return false;       
    }
};