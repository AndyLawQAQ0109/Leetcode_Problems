class Solution {
public:
    vector<vector<bool>> vis;
    int m, n;
    map<char, vector<vector<int>>> toVal; // Direction -> vector to update X & Y 
    map<vector<int>, char> toDir; // vector to update X & Y -> Direction
    
    vector<int> check(int x, int y, char r){
        for(int i=0; i<2; i++){
            int updateX = x + toVal[r][i][0], updateY = y + toVal[r][i][1];
            // cout<<updateX<<" "<<updateY<<endl;
            if(updateX >= 0 && updateX < m && 
               updateY >= 0 && updateY < n && 
               !vis[updateX][updateY]) 
                return toVal[r][i];
        }
        return {};        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<int> ans;
        for(int i=0; i<m; i++){
            vector<bool> tmp;
            for(int j=0; j<n; j++)
                tmp.push_back(false);
            vis.push_back(tmp);
        }
        toVal['R'] = {{0, 1}, {1, 0}};
        toVal['D'] = {{1, 0}, {0, -1}};
        toVal['L'] = {{0, -1}, {-1, 0}};
        toVal['U'] = {{-1, 0}, {0, 1}};
        
        toDir[{0, 1}] = 'R';
        toDir[{1, 0}] = 'D';
        toDir[{0, -1}] = 'L';
        toDir[{-1, 0}] = 'U';
        
        int i=0, j=0;
        char goingDir = 'R';
        while(!vis[i][j]){
            vis[i][j] = true;
            ans.push_back(matrix[i][j]);
            vector<int> tmp = check(i, j, goingDir);
            if(tmp.size() == 0)
                break;
            // cout<<"Ret: "<<tmp[0]<<" "<<tmp[1]<<endl;
            goingDir = toDir[tmp];
            i += tmp[0];
            j += tmp[1];
        }
        return ans;
    }
};
// Method 2:
vector<int> spiralOrder(vector<vector<int>>& matrix){
        int rS = 0, rE = matrix.size() - 1, cS = 0, cE = matrix[0].size() - 1;
        vector<int> ans;
        while(rS <= rE && cS <= cE){
            for(int i=cS; i<=cE; i++)
                ans.push_back(matrix[rS][i]);
            rS++;
            for(int i=rS; i<=rE; i++)
                ans.push_back(matrix[i][cE]);
            cE--;
            for(int i=cE; i>=cS && rS <= rE; i--)
                ans.push_back(matrix[rE][i]);
            rE--;
            for(int i=rE; i>=rS && cS <= cE; i--)
                ans.push_back(matrix[i][cS]);
            cS++;
        }
        return ans;
}
