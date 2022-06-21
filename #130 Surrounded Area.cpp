class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m <= 2 || n <= 2) return;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            visited[0][i] = true;
            visited[m-1][i] = true;
        }
        for(int i=1; i<m-1; i++){
            visited[i][0] = true;
            visited[i][n-1] = true;
        }

        for(int i=1; i<n-1; i++){ // 1st row
            if(board[0][i] == 'O')
                dfs(board, {1, i}, visited);
            if(board[m-1][i] == 'O')
                dfs(board, {m-2, i}, visited);
        }
        for(int i=1; i<m-1; i++){
            if(board[i][0] == 'O')
                dfs(board, {i, 1}, visited);
            if(board[i][n-1] == 'O')
                dfs(board, {i, n-2}, visited);
        }
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
    }
    void dfs(vector<vector<char>> &board, vector<int> index, vector<vector<bool>> &visited){
        int x = index[0], y = index[1];
        if(x < 0 || x > board.size() || y < 0 || y > board[0].size())
            return;
        if(visited[x][y] || board[x][y] == 'X')
            return;
        visited[x][y] = true;
        dfs(board, {x-1, y}, visited);
        dfs(board, {x+1, y}, visited);
        dfs(board, {x, y-1}, visited);
        dfs(board, {x, y+1}, visited);
    }
};
