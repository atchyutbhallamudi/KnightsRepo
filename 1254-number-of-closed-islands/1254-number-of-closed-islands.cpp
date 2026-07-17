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
        for(int i = 0; i < 4; i++){
            int xcor = x.F + dx[i];
            int ycor = x.S + dy[i];
            if(isValid({xcor,ycor})) neb.push_back({xcor,ycor});
        }
        return neb;
    }

    // DFS remains almost identical to your original code
    void dfs(state node, vector<vector<int>>& grid){
        vis[node.F][node.S] = 1;
        for(auto v : neighbours(node)){
            if(!vis[v.F][v.S]){
                // Remember: 0 is land in this specific problem
                if(grid[v.F][v.S] == 0){
                    dfs(v, grid);
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<int>>(m, vector<int>(n, 0));
        
        // Phase 1: Flood-fill and eliminate all islands touching the border
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // Check if we are on the outer edge
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (!vis[i][j] && grid[i][j] == 0) {
                        dfs({i,j}, grid); // Marks the whole invalid island as visited
                    }
                }
            }
        }

        // Phase 2: Count the remaining closed components
        int comp = 0;
        // Notice we only need to scan the inner grid (1 to m-2, 1 to n-2)
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    dfs({i,j}, grid);
                    comp++;
                }
            }
        }
        
        return comp;
    }
};