class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans  = 0;
        int head = -1, tail = 0;
        int n = nums.size();
        while(tail < n){
            while(head + 1 < n && mp[nums[head+1]] < k){
                head++;
                mp[nums[head]]+=1;
            }
            ans = max(ans,head-tail+1);
            if(tail < head){
                mp[nums[tail]]-=1;
                tail++;
            }
            else{
                mp[nums[tail]]-=1;
                tail++;
                head = tail-1;
            }
        }
        return ans;
    }
};