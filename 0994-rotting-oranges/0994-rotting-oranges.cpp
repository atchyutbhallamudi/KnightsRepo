class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Queue stores: {{row, col}, minute}
        queue<pair<pair<int, int>, int>> q;
        int freshCount = 0;
        
        // Step 1: Push all rotten oranges to queue and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // Minute 0 for initially rotten
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // If there are no fresh oranges, it takes 0 minutes
        if (freshCount == 0) return 0;
        
        int maxMinutes = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int minute = q.front().second; // This is your "entry minute"
            q.pop();
            
            // Track the maximum time it took to rot an orange
            maxMinutes = max(maxMinutes, minute);
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                // If it's in bounds and is a fresh orange
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // Mark as rotten (acts as our visited set)
                    freshCount--;     // Decrement fresh count
                    
                    // The core of your idea: next minute is parent + 1
                    q.push({{nr, nc}, minute + 1}); 
                }
            }
        }
        
        // Step 3: Check if any fresh oranges survived
        if (freshCount > 0) return -1;
        
        return maxMinutes;
    }
};