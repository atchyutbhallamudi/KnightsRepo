class Solution {
public:
    #define F first
    #define S second
    using state = pair<int,int>;
    vector<vector<int>> component;
    vector<int> reachable;
    vector<vector<int>> vis;
    int m,n;
    int dx[4]= {1,-1,0,0};
    int dy[4]= {0,0,1,-1};

    bool isValid(state node){
        if(node.F >= m || node.F < 0) return false;
        if(node.S >= n || node.S < 0) return false;
        return true;
    }

    vector<state> neighbours(state node){
        vector<state> neib;
        state newnode;
        for(int i = 0;i<4;i++){
            newnode.F = node.F + dx[i];
            newnode.S = node.S + dy[i];
            if(isValid(newnode)) neib.push_back(newnode);
        }
        return neib;
    }
    void dfs(state node , int compno, vector<vector<int>>& grid){
        vis[node.F][node.S] = 1;
        component[node.F][node.S] = compno;
        for(auto n : neighbours(node)){
            if(!vis[n.F][n.S] && grid[n.F][n.S] == 1)dfs(n,compno,grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<int>>(m,vector<int>(n,0));
        component = vector<vector<int>>(m,vector<int>(n,0));
        reachable.assign(m*n+1,0);
        int compno  = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j < n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    compno++;
                    dfs({i,j},compno,grid);
                }
            }
        }
        if(!compno) return 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j < n;j++){
                if(component[i][j] == 0) continue;
                reachable[component[i][j]]++;
            }
        }
        int ans  = -1;
        for(auto v : reachable){
            ans = max(ans,v);
        }
        return ans;
    }
};