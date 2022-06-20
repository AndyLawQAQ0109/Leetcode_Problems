// DFS
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

// BFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        for(int i=0; i<n; i++){
            if(isConnected[i][i] == 0) continue;
            isConnected[i][i] = 0;
            queue<int> q;
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    q.push(j);
                    isConnected[i][j] = 0;
                }
            }
            bfs(q, isConnected);
            count++;
        }
        return count;
    }
    void bfs(queue<int> q, vector<vector<int>>& isConnected){
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(!std::count(isConnected[curr].begin(), isConnected[curr].end(), 1))
                continue;
            isConnected[curr][curr] = 0;
            for(int i=0; i<isConnected[curr].size(); i++){
                if(isConnected[curr][i] == 1){
                    q.push(i);
                    isConnected[curr][i] = 0;
                }
            }
        }
    }
};
