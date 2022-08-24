class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n); // gas diff start from i
        for(int i=0; i<n; i++)
            diff[i] = gas[i] - cost[i];

        // iterate start from i = 0, and find end index j
        //
        // ***if j > i***, then any index between [i+1, j] can't finish a round
        // Prove by contradiction:
        // Assume i+1 can finish a round, that means i+1 can reach j+1,j+2...
        // Because i can reach i+1 (diff[i] >= 0) => i can reach j+1,j+2...
        // But i can only reach j. Therefore, [i+1, j] can't finish a round.
        // And we only need to consider *** index start from j+1 ****
        //
        // ***if j < i***, because we don't have to consider [i,size-1] Union [0,j]
        // We can simply use previous conclusion(start from j+1)
        // But j+1 is actually considered at previous iteration of i
        // Therefore, ***we can return -1***.
        //
        // ***if j == i***, then we can return i(Finished one round).
        for(int i=0; i<n; i++){
            int rest = diff[i];
            int j = i;
            while(rest >= 0){
                rest += diff[(j + 1) % n];
                j = (j + 1) % n;
                if(j == i)
                    return i;
            }
            if(j < i)
                return -1;
            i = j;
        }

        return -1;
    }
};
