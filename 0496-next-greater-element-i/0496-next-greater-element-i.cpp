class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size());
        vector<int> nextGreater(nums2.size());
        stack<int> s;

        // Step 1: Precompute next greater for nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] >= nums2[s.top()]) {
                s.pop();
            }
            if (s.empty()) {
                nextGreater[i] = -1;
            } else {
                nextGreater[i] = nums2[s.top()];
            }
            s.push(i);
        }

        // Step 2: Map nums2 elements to their next greater
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++) {
            map[nums2[i]] = nextGreater[i];
        }

        // Step 3: Build result using nums1
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = map[nums1[i]];
        }

        return result;
    }
};