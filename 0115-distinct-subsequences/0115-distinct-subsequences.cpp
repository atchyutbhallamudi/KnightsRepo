class Solution {
public:
    int rec(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // pr
        // bc
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;
        // cc
        if (dp[i][j] != -1)
            return dp[i][j];
        // transition
        int ans = 0;
        if (s[i] == t[j]) {
            ans += rec(i + 1, j, s, t,dp) + rec(i + 1, j + 1, s, t,dp);
        } else {
            ans += rec(i + 1, j, s, t,dp);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return rec(0, 0, s, t,dp);
    }
};