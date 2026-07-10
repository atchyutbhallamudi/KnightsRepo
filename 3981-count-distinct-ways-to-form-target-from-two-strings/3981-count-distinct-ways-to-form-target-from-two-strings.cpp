class Solution {
private:
    const int MOD = 1e9+7;
public:
    int dp[105][105][105][4];
    int rec(int i, int j,int k,int mask,string& word1, string& word2, string& target){
        //pr
        if(i > word1.size() || j > word2.size()) return 0;
        //base case
        if(k == target.size()){
            if(mask == 3) return 1;
            return 0;
        }
        //cc
        if(dp[i][j][k][mask] != -1) return dp[i][j][k][mask];
        //trans
        long long ans = 0;
        for(int nexti = i;nexti<word1.size();nexti++){
            if(word1[nexti] == target[k]) ans+=rec(nexti+1,j,k+1,mask|1,word1,word2,target);
        }
        for(int nextj = j;nextj<word2.size();nextj++){
            if(word2[nextj] == target[k]) ans+=rec(i,nextj+1,k+1,mask|2,word1,word2,target);
        }
        //sav and return
        return dp[i][j][k][mask] = (int)(ans%MOD);
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,0,word1,word2,target);
    }
};