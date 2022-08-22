class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int, vector<long long>> indices; // arr[i] -> [index]
        for(int i=0; i<arr.size(); i++){
            indices[arr[i]].push_back(i);
        }

        vector<long long> ans(arr.size(), 0);
        for(auto x: indices){
            vector<long long> v = x.second;
            vector<long long> sum_before_i(v.size() + 1);
            for(int i=0; i<v.size(); i++){
                sum_before_i[i+1] = sum_before_i[i] + v[i];
            }

            // indices: arr[i] -> {a0, a1, a2, a3}
            // ex. i = a2, then
            // sum = (a2-a0+a2-a1) + (a3-a2)
            // (# of elements before a2) * a2 - (sum of elements before a2) +
            // (sum of elements after a2) - (# of elements after a2) * a2
            for(int i=0; i<v.size(); i++){
                long long l = i * v[i] - sum_before_i[i];
                long long r = (sum_before_i[v.size()] - sum_before_i[i+1]) - (v.size() - i - 1) * v[i];
                ans[v[i]] = l + r;
            }
        }
        return ans;
    }
};

/*
// Time complexity O(N^2)
// Improved the nested loop as above
vector<long long> getDistances(vector<int>& arr) {
        map<int, vector<int>> indices; // arr[i] -> [index]
        for(int i=0; i<arr.size(); i++){
            indices[arr[i]].push_back(i);
        }
        vector<long long> ans;
        for(int i=0; i<arr.size(); i++){
            int tmp = 0;
            for(auto j: indices[arr[i]]){
                if(i == j)
                    continue;
                tmp += abs(j - i);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
*/
