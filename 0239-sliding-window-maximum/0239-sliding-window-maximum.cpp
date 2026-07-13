class Solution {
public:
    #define F first
    #define S second
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<pair<int,int>> dq;

        if(k == 1) return nums;
        
        // 1. Process the first window (up to k-1)
        dq.push_back({nums[0],0});
        for(int i = 1; i < k; i++){
            // Added !dq.empty() to prevent runtime errors
            while(!dq.empty() && nums[i] > dq.back().F){
                dq.pop_back();
            }
            // Changed push_front to push_back
            dq.push_back({nums[i],i}); 
        }
        
        // Max is now safely at the front
        ans.push_back(dq.front().F); 
        
        // 2. Process the rest of the array with left/right pointers
        int left = 0, right = k - 1;
        while(right < n - 1){
            left++;
            right++;

            // Pop smaller elements from the back (added empty check)
            while(!dq.empty() && nums[right] > dq.back().F){
                dq.pop_back();
            }
            // Push new element to the back
            dq.push_back({nums[right],right});

            // Remove out-of-bounds elements from the FRONT
            while(!dq.empty() && dq.front().S < left) {
                dq.pop_front(); 
            }

            // Max is at the front
            ans.push_back(dq.front().F);
        }

        return ans;
    }
};