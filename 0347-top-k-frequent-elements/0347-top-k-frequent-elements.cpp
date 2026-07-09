class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto v : nums){
            mp[v]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto v : mp){
            pq.push({-v.second,v.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            auto v = pq.top();
            ans.push_back(v.second);
            pq.pop();
        }
        return ans;
    }
};