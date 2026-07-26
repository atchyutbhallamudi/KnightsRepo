class Solution {
public:
    int dp[35][35];

    int rec(int i, int j, string& s, string& p) {
        // Base case: If we reached the end of pattern
        if (j == p.size()) return i == s.size();

        if (dp[i][j] != -1)return dp[i][j]; 

        // Check if current characters match
        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans = false;

        // Lookahead: Check if the next character in pattern is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Choice 1: Ignore 'char*' (use 0 times) -> move j past '*'
            // Choice 2: Use 'char*' (use 1+ times) -> advance i if first_match is true
            ans = rec(i, j + 2, s, p) || (first_match && rec(i + 1, j, s, p));
        } else {
            // Standard single character match
            ans = first_match && rec(i + 1, j + 1, s, p);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, s, p);
    }
};