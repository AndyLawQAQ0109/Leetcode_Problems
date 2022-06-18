class Solution {
void print(map<char, int> myMap){
    for(const auto& elem : myMap)
        std::cout << elem.first << "," << elem.second << "\t";
    cout<<endl;
}
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        vector<int> res;
        map<char, int> sm;
        map<char, int> pm;
        for(int i=0; i<p.size(); i++){
            sm[s[i]]++;
            pm[p[i]]++;
        }

        if(sm == pm) 
            res.push_back(0);
        
        for(int i=1; i<s.size()-p.size()+1; i++){
            sm[s[i-1]]--;
            if(sm[s[i-1]] == 0)
                sm.erase(s[i-1]);
            sm[s[i+p.size()-1]]++;
            if(sm == pm)
                res.push_back(i);
        }
        return res;
    }
};
