class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        if(size == 1)
            return "";
        for(int i=0, j=size-1; i<j; i++, j--){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[size-1] = 'b';
        return palindrome;
    }
};
