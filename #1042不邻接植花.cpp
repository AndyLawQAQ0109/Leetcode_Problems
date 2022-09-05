class Solution {
    
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        map<int, vector<int>> pathMap;
        for(int i=0; i<paths.size(); i++){
            vector<int> tmp = paths[i];
            pathMap[tmp[0]-1].push_back(tmp[1]-1);
            pathMap[tmp[1]-1].push_back(tmp[0]-1);
        }

        vector<int> res(n);
        for(int i=0; i<n; i++){
            int flowers[4] = {0};
            for(auto &p: pathMap[i])
                if(res[p] != 0)
                    flowers[res[p]-1] = 1;
            for(int j=0; j<4; j++){
                if(flowers[j] == 0){
                    res[i] = j+1;
                    break;
                }   
            }
        }
        /*
        for(int i=0; i<n; i++){
            // flowers[0] assigned to 1 when res[s] = 0. 
            // It means path 'p' hasn't use any flower yet.
            int flowers[5] = {0}; // 1-4 represents 4 flowers
            for(auto &p: pathMap[i])
                flowers[res[p]] = 1;
            for(int j=1; j<=4; j++){
                if(flowers[j] == 0){
                    res[i] = j;
                    break;
                }   
            }
        }
        */
        return res;
    }
};
