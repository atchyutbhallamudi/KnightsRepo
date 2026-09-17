class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        
        // dp[i][j] represents the ways to form j segments using the first i points (indices 0 to i)
        // We need n rows for indices 0 to n - 1.
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        
        // Base case: There is 1 way to form 0 segments (do nothing) for any point subset
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        
        // Build the DP table segment by segment
        for (int j = 1; j <= k; ++j) {
            long long prefix_sum = 0;
            
            // Iterate through each point index from 0 to n - 1
            for (int i = 0; i < n; ++i) {
                if (i > 0) {
                    dp[i][j] = (dp[i - 1][j] + prefix_sum) % MOD;
                }
                prefix_sum = (prefix_sum + dp[i][j - 1]) % MOD;
            }
        }
        
        // The answer using all n points (indices 0 to n - 1) to form k segments
        return dp[n - 1][k];
    }
};