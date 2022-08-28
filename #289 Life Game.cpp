class Solution {
    vector<vector<int>> dir = 
    {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, 
    {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    vector<vector<bool>> vis;
    int m, n;
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vis.resize(m, vector<bool>(n));

        dfs(board, 0, 0);
    }
    void dfs(vector<vector<int>> &board, int x, int y){
        if(x >= m || x < 0 || y >= n || y < 0 || vis[x][y])
            return;
        vis[x][y] = true;
        int cnt = 0;
        if(board[x][y] == 0){
            for(int i=0; i<dir.size(); i++){
                if(x+dir[i][0] >= m || x+dir[i][0] < 0 || y+dir[i][1] >= n || y+dir[i][1] < 0)
                    continue;
                if(board[x+dir[i][0]][y+dir[i][1]] == 1)
                    cnt++;
            }
            for(int i=0; i<dir.size(); i++)
                dfs(board, x+dir[i][0], y+dir[i][1]);
            if(cnt == 3)
                board[x][y] = 1;
        }
        else{
            for(int i=0; i<dir.size(); i++){
                if(x+dir[i][0] >= m || x+dir[i][0] < 0 || y+dir[i][1] >= n || y+dir[i][1] < 0)
                    continue;
                if(board[x+dir[i][0]][y+dir[i][1]] == 1)
                    cnt++;
            }
            for(int i=0; i<dir.size(); i++)
                dfs(board, x+dir[i][0], y+dir[i][1]);
            if(cnt < 2 || cnt > 3)
                board[x][y] = 0;
        }
    }
};
