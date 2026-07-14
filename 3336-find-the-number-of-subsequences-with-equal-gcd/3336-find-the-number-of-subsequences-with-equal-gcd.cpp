class Solution {
    int memo[201][201][201];
    int MOD = 1e9 + 7;
    int n;

    int dp(int i, int g1, int g2, const vector<int>& nums) {
        // Base case
        if (i == n) {
            return (g1 == g2 && g1 > 0) ? 1 : 0;
        }
        
        // Return precomputed answer if it exists
        if (memo[i][g1][g2] != -1) {
            return memo[i][g1][g2];
        }

        // Choice 1: Skip
        long long res = dp(i + 1, g1, g2, nums); 
        
        // Choice 2: Add to seq1
        res = (res + dp(i + 1,gcd(g1, nums[i]), g2, nums)) % MOD; 
        
        // Choice 3: Add to seq2
        res = (res + dp(i + 1, g1,gcd(g2, nums[i]), nums)) % MOD; 

        return memo[i][g1][g2] = res;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        
        // Initialize memoization table with -1
        memset(memo, -1, sizeof(memo));
        
        return dp(0, 0, 0, nums);
    }
};