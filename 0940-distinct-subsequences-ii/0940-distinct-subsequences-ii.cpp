class Solution {
public:
    int dp[2010];
    int n;
    #define MOD 1000000007
    // void rec(int level, string s){
    //     //pr
    //     //bc
    //     //cc
    //     //transition
    //     int ans = 0;
    //     for(int i = 0; i <= level-1;i++){
    //         dp[level]+=dp[i];
    //     }
    //     //snr
    //     return;
    // }
    int distinctSubseqII(string s) {
        memset(dp,0,sizeof(dp));
        n = s.size();
        int ans = 0;
        for(int level = 0;level <= n-1;level++){
            dp[level] = 1;
            for(int i = level - 1; i >= 0;i--){
                dp[level] = (dp[level] + dp[i])%MOD;
                if(s[level] == s[i]){
                    dp[level]--;
                    break;
                }
            }
        }
        for(int i = 0;i<n;i++)ans = (ans + dp[i])%MOD;
        return ans;
    }
};