class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1, m2;
        for(int i=0; i<nums1.size(); i++)
            m1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++)
            m2[nums2[i]]++;

        vector<int> res;
        int len1 = m1.size(), len2 = m2.size();      
        if(len1 < len2){
            for(pair<int, int> it: m1){
                if(m2[it.first] != 0){
                    int minVal = min(m2[it.first], m1[it.first]);
                    for(int i=0; i<minVal; i++)
                        res.push_back(it.first);
                }
            }
        }
        else{
            for(pair<int, int> it: m2){
                if(m1[it.first] != 0){
                    int minVal = min(m2[it.first], m1[it.first]);
                    for(int i=0; i<minVal; i++)
                        res.push_back(it.first);
                }
            }
        }
        return res;
    }
};
