class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
            return;
        }
        if(n == 0) return;
        int size = nums1.size();
        int i=0, j=0;
        while(i < size && j < n){
            if(nums2[j] > nums1[i]){
                while(i < m && nums2[j] > nums1[i+1]){
                    i++;
                }           
                for(int index=size-2; index>=i; index--){
                    nums1[index+1] = nums1[index];
                }
                if(i < m)
                    nums1[++i] = nums2[j];
                else
                    nums1[i++] = nums2[j];
                j++;
                m++;
            }
            else{
                for(int index=size-2; index>=i; index--){
                    nums1[index+1] = nums1[index];
                }
                nums1[i++] = nums2[j];
                j++;
                m++;
            }
        }
    }

};


////
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last=m+n-1;
        while(n){
            if(m==0||nums1[m-1]<=nums2[n-1]){
                nums1[last--]=nums2[--n];
            }else{
                nums1[last--]=nums1[--m];
            }
        }
    }
};
