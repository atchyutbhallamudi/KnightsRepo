class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n > m) return false;

        vector<int> pre(m, 0);
        int i = 0, j = 0;
        
        // 1. YOUR EXACT LOGIC (Forward Pass)
        while (j < m) {
            if (i < n && s[i] == t[j]) {
                i++; // Found a match, move 'i'
            }
            pre[j] = i; // Record how many characters we successfully matched so far
            j++;
        }
        
        // If your forward loop matched everything, we don't even need a replacement!
        if (pre[m - 1] == n) return true;
        
        vector<int> suf(m, 0);
        i = n - 1; 
        j = m - 1;
        int count = 0; 
        
        // 2. YOUR EXACT LOGIC (Backward Pass)
        while (j >= 0) {
            if (i >= 0 && s[i] == t[j]) {
                i--; // Found a match from the end, move 'i' backwards
                count++;
            }
            suf[j] = count; // Record how many characters we successfully matched from the end
            j--;
        }
        
        // 3. Find the perfect spot for the replacement
        // We loop through 't' and say: "If I replace t[k], do the forward matches 
        // before 'k' + the backward matches after 'k' equal the rest of 's'?"
        for (int k = 0; k < m; k++) {
            int left_matches = (k > 0) ? pre[k - 1] : 0;
            int right_matches = (k < m - 1) ? suf[k + 1] : 0;
            
            // We need to match n-1 characters (since 1 character is replaced at t[k])
            if (left_matches + right_matches >= n - 1) {
                return true;
            }
        }
        
        return false;
    }
};