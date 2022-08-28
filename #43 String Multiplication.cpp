class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size(); 
        int n = num2.size();
        string ans(m+n, '0');
        for(int i=m-1; i>=0; i--){
            string curr = "  ";
            int n1 = num1[i] - '0';
            for(int j=n-1; j>=0; j--){
                int n2 = num2[j] - '0';
                int prod = n1 * n2;
                curr[1] = prod % 10 + '0';
                curr[0] = prod / 10 + '0';
                add(ans, curr, i+j+1);
            }
        }
        int i = 0;
        while(ans[i] == '0')
            i++;
        return ans.substr(i);
    }
    void add(string &ans, string curr, int idx){
        int a1 = ans[idx] - '0', a0 = ans[idx-1] - '0';
        int c1 = curr[1] - '0', c0 = curr[0] - '0';
        bool addOne = false;
        if(a1 + c1 < 10){
            ans[idx] = (a1 + c1) + '0';
        }
        else{
            ans[idx] = (a1 + c1 - 10) + '0';
            addOne = true;
        }
        int total = addOne ? (a0 + c0 + 1) : (a0 + c0);
        if(total < 10)
            ans[idx-1] = total + '0';
        else{
            ans[idx-1] = total - 10 + '0';
            int index = idx-2;
            ans[index]++;
            while(index > 0 && ans[index] == '9' + 1){
                ans[index] = '0';
                ans[index-1]++;
            }
        }
    }
};
