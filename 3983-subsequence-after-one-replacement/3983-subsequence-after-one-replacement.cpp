class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (n > m) return false;

        // 1. Build L array: Earliest matching indices from the left
        vector<int> L(n, -1);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j < m) L[i] = j++;
            else break;
        }

        // If the left pass matched everything, no replacement is even needed!
        if (L[n - 1] != -1) return true; 

        // 2. Build R array: Latest matching indices from the right
        vector<int> R(n, -1);
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j >= 0) R[i] = j--;
            else break;
        }

        // 3. Find if there is a valid gap to replace s[i]
        for (int i = 0; i < n; i++) {
            // Check if the left and right segments actually exist/matched
            bool left_ok = (i == 0) || (L[i - 1] != -1);
            bool right_ok = (i == n - 1) || (R[i + 1] != -1);

            if (left_ok && right_ok) {
                // Determine the boundaries of the gap in 't'
                int left_idx = (i == 0) ? -1 : L[i - 1];
                int right_idx = (i == n - 1) ? m : R[i + 1];
                
                // If there is at least one unused character between them
                if (left_idx + 1 < right_idx) {
                    return true;
                }
            }
        }

        return false;
    }
};