class Solution {
    bool flag = false;
public:
    bool checkPowersOfThree(int n) {
        return dfs(n, 0, 0);
    }
    bool dfs(int n, int currSum, int currPow){
        if(flag){
            return true;
        }   
        if(currSum > n)
            return false; 
        if(currSum == n){
            flag = true;
            return true;
        }
        
        for(int i=currPow; i<=14; i++){
            if(dfs(n, currSum + (int)pow(3, i), i + 1))
                return true;
        }
        return false;
    }
};
