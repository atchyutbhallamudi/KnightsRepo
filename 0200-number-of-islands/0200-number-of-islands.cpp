class Solution {
public:
    #define F first
    #define S second
    using state = pair<int,int>;
    vector<vector<int>> vis;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int m,n;

    bool isValid(state s){
        if(s.F < 0 || s.F >= m) return false;
        if(s.S < 0 || s.S >= n) return false;
        return true;
    }
    vector<state> neighbours(state x){
        vector<state> neb;
        for(int i = 0;i<4;i++){
            int xcor = x.F + dx[i];
            int ycor = x.S + dy[i];
            if(isValid({xcor,ycor})) neb.push_back({xcor,ycor});
        }
        return neb;
    }
    void dfs(state node,vector<vector<char>>& grid){
        vis[node.F][node.S] = 1;
        for(auto v : neighbours(node)){
            if(!vis[v.F][v.S]){
                if(grid[v.F][v.S] == '1'){
                    dfs(v,grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<int>>(m,vector<int>(n,0));
        int comp = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs({i,j},grid);
                    comp++;
                }
            }
        }
        return comp;
    }
};