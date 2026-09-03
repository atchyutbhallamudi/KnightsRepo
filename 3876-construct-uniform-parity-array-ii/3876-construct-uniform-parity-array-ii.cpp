class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        if(nums1[0]%2) return true;
        for(auto v : nums1) if(v%2) return false;
        return true;   
    }   
};