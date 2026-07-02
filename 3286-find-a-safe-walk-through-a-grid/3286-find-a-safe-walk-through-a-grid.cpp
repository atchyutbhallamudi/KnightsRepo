class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dist[x][y] stores the minimum damage taken to reach (x, y)
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        
        // Initialize the starting cell
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // If the neighbor is within bounds
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int cost = grid[nx][ny];
                    
                    // Relaxation step: If we found a path with less damage
                    if (dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;
                        
                        // 0-cost moves go to the front, 1-cost moves go to the back
                        if (cost == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        
        // Check if the remaining health after taking the minimum possible damage is >= 1
        return (health - dist[m-1][n-1]) >= 1;
    }
};