class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
    
        int n1 = nums1.size(), n2 = nums2.size();
        long long a = 0, b = 0, t = 0, i = 0, j = 0;

        while (i < n1 && j < n2)
            if (nums1[i] > nums2[j])
                b += nums2[j++];
            else if (nums1[i] < nums2[j])
                a += nums1[i++];
            else {
                t += max(a, b) + nums1[i];
                i++;
                j++;
                a = 0;
                b = 0;
            }

        while (i < n1)
            a += nums1[i++];

        while (j < n2)
            b += nums2[j++];

        t += max(a, b);

        return t%((int) (1e9+7));
    }
};