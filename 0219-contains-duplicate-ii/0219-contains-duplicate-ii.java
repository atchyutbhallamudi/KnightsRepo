class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
         Set<Integer> hm = new HashSet<>();
        for(int i = 0; i < nums.length;i++){
            if(hm.contains(nums[i])){
                return true;
            }
            hm.add(nums[i]);
            if(hm.size()>k) hm.remove(nums[i-k]);
        } 
    return false;      
    }
}