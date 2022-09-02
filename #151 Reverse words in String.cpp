class Solution {
public:
    string reverseWords(string s) {
        // Remove front & back spaces
        int i = 0, j = s.size() - 1;
        while(s[i] == ' ')
            i++;
        while(s[j] == ' ')
            j--;
        s = s.substr(i, j-i+1);
        
        // Remove extra spaces 
        i = 0;
        while(i<s.size()){
            if(s[i] == ' ' && s[i-1] == ' ')
                s.erase(i, 1);
            else
                i++;
        }

        // Reverse entire string
        reverse(s.begin(), s.end());

        // Reverse each word
        int l = 0, r = 0;
        while(r < s.size()){
            if(s[r] == ' '){
                reverse(s.begin()+l, s.begin()+r);
                l = r+1;
            }
            else if(r == s.size() - 1){
                reverse(s.begin()+l, s.end());
                l = r+1;
            }
            r++;
        }
        return s;
    }
};
