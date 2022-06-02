public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int num = 0;
        while(n != 0){
            if((n & 1) == 1) num++;
            n = n >>> 1;
        }
        return num;
    }
}
