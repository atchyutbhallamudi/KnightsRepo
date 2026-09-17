class Solution {
public:
    long long dp[1001][1001];
    long long MOD = 1e9 + 7;

    long long rec(int i, int j) {
        //bc
        if (j == 0) return 1; 
        if (i < j) return 0;  
        
        if (dp[i][j] != -1) return dp[i][j];

        long long ans ;
        ans = (2 * rec(i - 1, j) - rec(i - 2, j) + rec(i - 1, j - 1)) % MOD;

        // Handle negative modulo values in C++
        if (ans < 0) ans += MOD;
        // Save and return
        return dp[i][j] = ans;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return rec(n - 1, k);
    }
};