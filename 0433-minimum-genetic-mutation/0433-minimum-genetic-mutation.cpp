class Solution {

private: 
    bool wordDiff(string w1, string w2){
        int count = 0;
        for(int i = 0;i<8;i++){
            if(w1[i] != w2[i])count++;
        }
        return count==1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0;
        if(bank.size() == 0) return -1;
        int n = bank.size();
        int count = 0;
        while(count < n && bank[count] != endGene)count++;
        if(count == n) return -1;
        bank.push_back(startGene);
        bank.push_back(endGene);
        vector<vector<int>>g(n+2);
        for(int i = 0;i<n+2;i++){
            for(int j = 0;j<n+2;j++){
                if(i==j)continue;
                if(wordDiff(bank[i],bank[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        queue<int> q;
        vector<int> vis(n+2,0);
        vector<int> dis(n+2,1e9);
        q.push(n);
        dis[n] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(vis[curr]) continue;
            vis[curr] = 1;
            if(curr == n+1){
                return dis[n+1];
            }
            for(auto v : g[curr]){
                if(!vis[v] && dis[v] > 1 + dis[curr]){
                    dis[v] = 1 + dis[curr];
                    q.push(v);
                }
            }
        }
        return -1;
    }
};