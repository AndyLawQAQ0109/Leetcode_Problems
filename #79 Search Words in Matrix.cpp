class Solution {
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        if(word.size() > m * n) return false;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, vis)) 
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int i, int j, vector<vector<bool>> &vis){
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j])
            return false;
        if(board[i][j] != word[0])
            return false;
        if(word.size() == 1) 
            return true;

        vis[i][j] = true;
        word.erase(0, 1);
        if(dfs(board, word, i - 1, j, vis))
            return true;
        if(dfs(board, word, i + 1, j, vis))
            return true;
        if(dfs(board, word, i, j - 1, vis))
            return true;
        if(dfs(board, word, i, j + 1, vis))
            return true;
        vis[i][j] = false;
        return false;
    }
};
