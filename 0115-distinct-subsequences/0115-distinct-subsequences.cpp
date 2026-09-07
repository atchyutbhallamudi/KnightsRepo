class Solution {
public:
    int dp[1010][1010];
    int rec(int i, int j, string& s, string& t){
        //pr
        //bc
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        //cc
        if(dp[i][j] != -1) return dp[i][j];
        //transition
        int ans = 0;
        if(s[i] == t[j]){
            ans+=rec(i+1,j,s,t) + rec(i+1,j+1,s,t);
        }
        else{
            ans+= rec(i+1,j,s,t);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,t);  
    }
};