class Solution {
    vector<int> values_;
    int maxTime_;
    vector<bool> vis;
    int ans;
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int size = values.size();
        vector<vector<pair<int, int>>> graph(size);
        for(auto& e : edges){
            graph[e[0]].push_back(make_pair(e[1], e[2]));
            graph[e[1]].push_back(make_pair(e[0], e[2]));
        }

        values_ = values;
        maxTime_ = maxTime;
        vis = vector<bool>(size);
        ans = 0;
        vis[0] = true;
        dfs(0, values[0], 0, graph);

        return ans;
    }
    void dfs(int currNode, int currVal, int currTime, vector<vector<pair<int, int>>> &graph){
        if(currTime > maxTime_)
            return;
        if(currNode == 0)
            ans = max(currVal, ans);
        for(auto& node : graph[currNode]){
            // node.first: next node
            // node.second: time for arriving to next node
            if(!vis[node.first]){
                vis[node.first] = true;
                dfs(node.first, currVal + values_[node.first], currTime + node.second, graph);
                vis[node.first] = false;
            }
            else
                dfs(node.first, currVal, currTime + node.second, graph);
        }
    }
};
