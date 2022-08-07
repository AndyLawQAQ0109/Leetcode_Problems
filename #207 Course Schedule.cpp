class Solution {
    //status[i] = 0: Not searched yet
    //status[i] = 1: Searching
    //status[i] = 2: Searched
    vector<int> status;
    bool res = true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = prerequisites.size();
        if(size == 0) 
            return true;

        status = vector<int>(numCourses);
        map<int, vector<int>> graph;
        for(auto &c : prerequisites){
            // Both are OK
            graph[c[0]].push_back(c[1]);
            // graph[c[1]].push_back(c[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(status[i] == 0)
                dfs(i, graph);
        }
        return res;
    }
    void dfs(int course, map<int, vector<int>> &graph){
        status[course] = 1;
        for(auto &c : graph[course]){
            if(status[c] == 0)
                dfs(c, graph);
            else if(status[c] == 1){
                res = false;
                return;
            }
        }
        status[course] = 2;
    }
    /*4
    [[0,1],[0,2],[1,2],[1,3]]*/
};
