class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int dp[52][52][104];
    bool vis[52][52]; // Tracks the active path to prevent cycles

    int rec(int x, int y, int health, vector<vector<int>>& grid){
        // If health drops to 0 or below, this path fails
        if(health <= 0) return 0;
        
        // Base case: Reached the end. 
        // Health was already deducted in the previous transition.
        if(x == grid.size()-1 && y == grid[0].size()-1){
            return 1; 
        }
        
        // Return computed state
        if(dp[x][y][health] != -1) return dp[x][y][health];
        
        // Cycle prevention: if we are already visiting this cell in the current path
        if(vis[x][y]) return 0;
        
        // Mark current cell as part of the active path
        vis[x][y] = true;
        
        int ans = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()){
                if(grid[nx][ny]) ans = ans | rec(nx, ny, health - 1, grid);
                else ans = ans | rec(nx, ny, health, grid);
                
                // Early exit: if we found a valid path, no need to keep searching
                if(ans == 1) break; 
            }
        }
        
        // Unmark the cell so other paths can use it
        vis[x][y] = false;
        
        return dp[x][y][health] = ans;
    }
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        
        // Deduct health for the starting cell immediately
        if(grid[0][0]) health -= 1;
        
        // If the starting cell kills us instantly
        if(health <= 0) return false;
        
        return rec(0, 0, health, grid);
    }
};