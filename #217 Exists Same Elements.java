class Solution {
    public boolean containsDuplicate(int[] nums) {
        int len = nums.length;
        HashMap<Integer, Integer> each = new HashMap<Integer, Integer>();
        for(int i=0; i<len; i++){
            if(each.get(nums[i]) == null)
                each.put(nums[i], 1);
            else
                return true;
        }
        return false;
    }
}
