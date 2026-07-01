class Solution {
public:
    int top;
    int dp[1010][1010];
    int rec(int currlen, int copiedlen){
        //pr
        if(currlen > top) return 1e9;
        //bc
        if(currlen == top) return 0;
        //cc
        if(dp[currlen][copiedlen] != -1) return dp[currlen][copiedlen];
        //trans
        int ans = 1e9;
        //copy;
        if(copiedlen < currlen)ans = 1 + rec(currlen,currlen);
        //paste
        if(copiedlen) ans = min(ans,1+rec(currlen + copiedlen,copiedlen));
        //sav and ret
        return dp[currlen][copiedlen] = ans;
    }
    int minSteps(int n){
        top = n;
        memset(dp,-1,sizeof(dp));
        return rec(1,0);
    }
};