class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> open;
        dfs(rooms,0,open);
        return open.size()==rooms.size();
    }
    
    void dfs(vector<vector<int>>& rooms,int curr,unordered_set<int>& open){
        if(open.find(curr) == open.end()) 
            open.insert(curr);
        for (int i=0;i<rooms[curr].size();i++){
            if(open.find(rooms[curr][i]) == open.end())
                open.insert(rooms[curr][i]);
            else
                continue;
            dfs(rooms,rooms[curr][i],open);
        }
    }
};
