class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        int i = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            dfs(isConnected, visited, i);
            count++;
        }

        return count;
    }
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int i){
        if(visited[i]) return;
        visited[i] = true;
        for(int j=0; j<isConnected[i].size(); j++){
            if(i != j && isConnected[i][j] == 1){
                dfs(isConnected, visited, j);
            }
        }
    }
};
