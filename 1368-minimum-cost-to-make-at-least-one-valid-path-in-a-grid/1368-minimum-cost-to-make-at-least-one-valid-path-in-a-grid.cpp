class Solution {
public:
    #define F first
    #define S second
    using state = pair<int,pair<int,int>>;
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> dist;
    bool isValid(pair<int,int> curr){
        if(curr.F < 0 || curr.F >=m || curr.S < 0 || curr.S >= n) return false;
        return true;
    }
    vector<state> neighbours(pair<int,int> curr, vector<vector<int>>& grid){
        vector<state> neib;
        for(int i = 0;i<=3;i++){
            int newx,newy;
            newx = curr.F + dx[i];
            newy = curr.S + dy[i];
            if(!isValid({newx, newy})) continue;
            if(i+1 == grid[curr.F][curr.S]){
                neib.push_back({0,{newx,newy}});
            }
            else{
                neib.push_back({1,{newx,newy}});
            }
        }
        return neib;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dist = vector<vector<int>>(m,vector<int>(n,1e9));
        deque<state> dq;
        dq.push_back({0,{0,0}});
        dist[0][0] = 0;
        while(!dq.empty()){
            state curr  = dq.front();
            dq.pop_front();
            for(auto v : neighbours(curr.S,grid)){
                if(v.F == 1 && dist[v.S.F][v.S.S] > 1 + dist[curr.S.F][curr.S.S]){
                    dist[v.S.F][v.S.S] = 1 + dist[curr.S.F][curr.S.S];
                    dq.push_back({1,v.S});
                }
                else if(v.F == 0 && dist[v.S.F][v.S.S] > dist[curr.S.F][curr.S.S]){
                    dist[v.S.F][v.S.S] = dist[curr.S.F][curr.S.S];
                    dq.push_front({0,v.S});
                }
            }
        }
        return dist[m-1][n-1];
    }
};