class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> prev = generate(numRows-1);
        vector<int> append(prev.size()+1, 0);
        append[0] = 1; append[append.size()-1] = 1;
        for(int i=1; i<append.size()-1; i++){
            append[i] = prev[numRows-2][i-1] + prev[numRows-2][i];
        }
        prev.push_back(append);
        return prev;
    }
};
