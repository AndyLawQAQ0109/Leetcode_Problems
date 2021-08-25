#include <map>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::map<char, string> store;
        store.insert(pair <char, string>('2',"abc"));
        store.insert(pair <char, string>('3',"def"));
        store.insert(pair <char, string>('4',"ghi"));
        store.insert(pair <char, string>('5',"jkl"));
        store.insert(pair <char, string>('6',"mno"));
        store.insert(pair <char, string>('7',"pqrs"));
        store.insert(pair <char, string>('8',"tuv"));
        store.insert(pair <char, string>('9',"wxyz"));

        vector<string> res = vector<string>();

        int len = digits.length(); // length of input
        if(len == 0)
            return res;
        else{
            string part(len, '_');
            passIn(digits, len, store, part, res);
        }
        return res;
    }
    void passIn(string digits, int len, std::map<char, string> store, string partial_res, vector<string> &res){
        if(len == 0)
            res.push_back(partial_res);
        else{
            char last_digit = digits[len-1];
            string value = store[last_digit];

            string digits_(len-1, '_');
            for(int i=0;i<len-1;i++)
                digits_[i] = digits[i];

            for(int i=0;i<value.length();i++){
                string temp = partial_res;
                temp[len-1] = value[i];
                // cout<<"last("<<value<<"):"<<temp<<"\n";

                passIn(digits_, len-1, store, temp, res);
            }
        }
    }
};