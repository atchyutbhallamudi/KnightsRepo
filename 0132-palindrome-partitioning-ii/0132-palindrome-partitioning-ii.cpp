class Solution {
private:
    struct RollingHash {
        int n;
        const long long B1 = 313, M1 = 1e9 + 7;
        const long long B2 = 317, M2 = 1e9 + 9;

        vector<long long> h1, h2, p1, p2;
        vector<long long> rh1, rh2;

        RollingHash(const string& s) {
            n = s.length();
            h1.assign(n + 1, 0);
            h2.assign(n + 1, 0);
            p1.assign(n + 1, 1);
            p2.assign(n + 1, 1);
            rh1.assign(n + 1, 0);
            rh2.assign(n + 1, 0);

            // Compute prefix powers and forward hashes
            for (int i = 0; i < n; i++) {
                p1[i + 1] = (p1[i] * B1) % M1;
                p2[i + 1] = (p2[i] * B2) % M2;
                h1[i + 1] = (h1[i] * B1 + s[i]) % M1;
                h2[i + 1] = (h2[i] * B2 + s[i]) % M2;
            }

            // Compute reverse hashes on reversed string
            for (int i = 0; i < n; i++) {
                rh1[i + 1] = (rh1[i] * B1 + s[n - 1 - i]) % M1;
                rh2[i + 1] = (rh2[i] * B2 + s[n - 1 - i]) % M2;
            }
        }

        // Forward hash of s[l...r]
        pair<long long, long long> getForward(int l, int r) {
            long long hash1 = (h1[r + 1] - (h1[l] * p1[r - l + 1]) % M1 + M1) % M1;
            long long hash2 = (h2[r + 1] - (h2[l] * p2[r - l + 1]) % M2 + M2) % M2;
            return {hash1, hash2};
        }

        // Reverse hash of s[l...r]
        pair<long long, long long> getReverse(int l, int r) {
            int rev_l = n - 1 - r;
            int rev_r = n - 1 - l;
            long long hash1 = (rh1[rev_r + 1] - (rh1[rev_l] * p1[rev_r - rev_l + 1]) % M1 + M1) % M1;
            long long hash2 = (rh2[rev_r + 1] - (rh2[rev_l] * p2[rev_r - rev_l + 1]) % M2 + M2) % M2;
            return {hash1, hash2};
        }

        // A substring is a palindrome if its forward and backward hashes match
        bool isPalindrome(int l, int r) {
            return getForward(l, r) == getReverse(l, r);
        }
    };

    int solve(int i, int n, RollingHash& hasher, vector<int>& dp) {
        // If the remaining suffix s[i...n-1] is already a palindrome, no cuts needed
        if (hasher.isPalindrome(i, n - 1)) return 0;

        if (dp[i] != -1) return dp[i];

        int minCuts = INT_MAX;
        for (int j = i; j < n; j++) {
            if (hasher.isPalindrome(i, j)) {
                int nextCuts = solve(j + 1, n, hasher, dp);
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

        RollingHash hasher(s);
        vector<int> dp(n, -1);

        return solve(0, n, hasher, dp);
    }
};