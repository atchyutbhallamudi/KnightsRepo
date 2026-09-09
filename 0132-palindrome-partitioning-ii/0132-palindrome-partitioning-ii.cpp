class Solution {
private:
    bool checkPalindrome(string &s, int i, int j, vector<vector<int>> &palMemo) {
        if (i >= j) return true;
        if (palMemo[i][j] != -1) return palMemo[i][j];

        if (s[i] != s[j]) {
            return palMemo[i][j] = 0;
        }
        return palMemo[i][j] = checkPalindrome(s, i + 1, j - 1, palMemo);
    }

    int solve(int i, int n, const vector<vector<int>> &palMemo, vector<int> &dp) {
        // If the remaining suffix s[i...n-1] is already a palindrome, 0 cuts needed
        if (palMemo[i][n - 1] == 1) return 0;
        if (dp[i] != -1) return dp[i];

        int minCuts = INT_MAX;
        for (int j = i; j < n; j++) {
            if (palMemo[i][j] == 1) {
                int nextCuts = solve(j + 1, n, palMemo, dp);
                if (nextCuts != INT_MAX) {
                    minCuts = min(minCuts, 1 + nextCuts);
                }
            }
        }

        return dp[i] = minCuts;
    }

public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // palMemo[i][j]: -1 = unvisited, 0 = false, 1 = true
        vector<vector<int>> palMemo(n, vector<int>(n, -1));

        // Pre-fill the memoization table
        for (int i = 0; i < n; i++) {
            palMemo[i][i] = 1; // Single character is always a palindrome
            for (int j = i + 1; j < n; j++) {
                palMemo[i][j] = checkPalindrome(s, i, j, palMemo);
            }
        }

        vector<int> dp(n, -1);
        return solve(0, n, palMemo, dp);
    }
};