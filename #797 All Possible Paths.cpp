class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> tmp;
        vector<vector<int>> partial = dfs(graph, 0, tmp);
        res.insert(res.end(), partial.begin(), partial.end());

        return res;
    }
    vector<vector<int>> dfs(vector<vector<int>> &graph, int nextNode, vector<int> &tmp){
        vector<vector<int>> res;       
        if(nextNode == graph.size() - 1){
            tmp.push_back(nextNode);
            res.push_back(tmp);
            return res;
        }
        if(graph[nextNode].size() == 0)
            return {{}};
            
        tmp.push_back(nextNode);
        vector<int> t = tmp;
        for(int i=0; i<graph[nextNode].size(); i++){     
            tmp = t;
            vector<vector<int>> partial = dfs(graph, graph[nextNode][i], tmp);
            if(partial.size() == 1 && partial[0].size() == 0)
                continue;
            else
                res.insert(res.end(), partial.begin(), partial.end());
        }
        return res;
    }
};
