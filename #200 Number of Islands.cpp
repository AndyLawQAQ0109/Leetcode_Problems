class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {       
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>> &grid, int i, int j){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] == '1'){
                grid[x][y] = '0';
                q.push(make_pair(x-1, y));
                q.push(make_pair(x+1, y));
                q.push(make_pair(x, y-1));
                q.push(make_pair(x, y+1));
            }
        }
    }
};
