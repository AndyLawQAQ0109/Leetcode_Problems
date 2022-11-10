class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int size = nums.size();
        // BASE CONDITION 1:
    // if there is only one number then min and max are the same number so [(max(A) - min(A))] = 0
    if(size == 1)
        return 0;
    // WHY SORT THE ARRAY ?
    // REASON: 
    // (i) we know for some numbers we will add k and for others we will subtract k.
    // (ii) for smaller numbers we will add k and for larger numbers we will subtract k.         
    // (iii) We will sort the array so that we have an increasing order of number 
    //       which will help divide the array into 2 segments.
    //       SEGMENT LEFT: numbers where we add k
    //       SEGMENT RIGHT: numbers where we subtract k
    sort(nums.begin(), nums.end());
    // if k >= [(max(A) - min(A))]
    // then cannot add k to some numbers (**AND**) subtract k from others BECAUSE THIS WILL INCREASE [(max(A) - min(A))]
    // you can either add k (**OR**) subtract k BECAUSE THIS WILL maintain the original [(max(A) - min(A))]
    // Eg: A = [1,2,3,4,5] k = 4
    // Original Difference = max(A)-min(A) = 4
    // CASE 1: Adding k to each A = [5,6,7,8,9]
    // CASE 2: Subtracting k from each A = [-3,-2,-1,0,1]
    // In both the CASES the max(A)-min(A) = 4 that is the Original Difference.
    // If we try to add k for some and subtract k for others 
    // then we will find SMALLER min(A) or LARGER max(A) which will increase max(A)-min(A).
    // BASE CONDITION 2: if we will find k >= max(A)-min(A) then return max(A)-min(A)
    if(k >= nums[size-1] - nums[0])
        return nums[size-1] - nums[0];
    // To decrease the [max(A)-min(A)] we will add k to first 'x' numbers and subtract k from remaining numbers.
    // SEGMENT LEFT: First 'x' numbers where we add k i.e (A[0]+k, A[1]+k, ..., A[i]+k)
    // SEGMENT RIGHT: Rest all numbers where we subtract k i.e (A[i+1]-k, A[i+2]-k, ..., A[SIZE-1]-k)
    // Now the Question is TILL WHERE WE WILL ADD K AND THEN SUBTRACT K ?
    // ANSWER: We have to check for all possibilities(i.e all possible ways to divide A into SEGMENT LEFT and SEGMENT RIGHT).
    // HOW WE WILL FIND min(A) AND max(A) ?
    // ANSWER: Think of the LEFT SEGEMENT and RIGHT SEGMENT as 2 separate sorted arrays
    // we know the numbers are in increasing order in each SEGMENT
    // SEGMENT LEFT:(A[0]+k, A[1]+k, ..., A[i]+k)
    //                 ^                      ^
    //                 |                      |
    //           this can be minimum     this can be maximum
    // SEGMENT RIGHT:(A[i+1]-k, A[i+2]-k, ..., A[SIZE-1]-k)
    //                   ^                      ^
    //                   |                      |
    //           this can be minimum     this can be maximum
    // i.e min(A) = min(min(SEGMENT LEFT), min(SEGMENT RIGHT)) i.e min(A) = min(A[0]+k, A[i+1]-k)
    // and max(A) = max(max(SEGMENT LEFT), max(SEGMENT RIGHT)) i.e max(A) = max(A[i]+k, A[SIZE-1]-k)
    // we will return the minimumm [max(A)-min(A)] of all possibilities.        
    int minScore = nums[size-1]-nums[0];
    for(int i=0;i<size-1;i++){
        int mn = min(nums[0]+k, nums[i+1]-k);
        int mx = max(nums[i]+k, nums[size-1]-k);
        minScore = min(minScore, mx-mn);
    }
    return minScore;
    }
};
