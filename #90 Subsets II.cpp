class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums[0];
        nums.erase(nums.begin());
        return recurr(n, nums);
    }
    vector<vector<int>> recurr(int n, vector<int> &nums){
        if(nums.size() == 0)
            return {{}, {n}};
        
        vector<vector<int>> res = {{}, {n}};
        int n_ = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> prev = recurr(n_, nums);
        for(int i=1; i<prev.size(); i++){
            vector<int> tmp = prev[i];           
            if(tmp.size() > 1 || (tmp.size() == 1 && tmp[0] != n)){
                cout<<tmp.size()<<" "<<n<<endl;
                sort(tmp.begin(), tmp.end());
                if(count(res.begin(), res.end(), tmp) == 0)
                    res.push_back(tmp);
            }

            tmp.insert(tmp.begin(), n);
            sort(tmp.begin(), tmp.end());
            if(count(res.begin(), res.end(), tmp) == 0)
                res.push_back(tmp);            
        }
        return res;
    }
};
