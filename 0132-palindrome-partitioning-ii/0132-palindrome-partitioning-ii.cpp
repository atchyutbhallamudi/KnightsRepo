class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // dp[i] = minimum cuts needed for s[0...i]
        vector<int> dp(n);

        // palindrome[i][j] = whether s[i...j] is a palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i] = i;

            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i] && 
                    (i - j <= 1 || palindrome[j + 1][i - 1])) {
                    
                    palindrome[j][i] = true;

                    if (j == 0)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};