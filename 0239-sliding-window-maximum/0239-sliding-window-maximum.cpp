class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        if(k == 1) return nums;

        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        int left = 0, right = k - 1;
        while(right < n - 1){
            left++;
            right++;

            pq.push({nums[right], right});

            while(!pq.empty() && pq.top().second < left) pq.pop();

            ans.push_back(pq.top().first);
            
        }

        return ans;

    }
};