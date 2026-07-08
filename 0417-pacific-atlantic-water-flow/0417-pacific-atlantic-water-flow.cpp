class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Helper method replacing the lambda
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& track, const vector<vector<int>>& heights, int mask) {
        int m = heights.size();
        int n = heights[0].size();
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                // Check bounds, ensure uphill flow, and verify this ocean hasn't visited yet
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                    heights[nr][nc] >= heights[r][c] && 
                    !(track[nr][nc] & mask)) {
                    
                    track[nr][nc] |= mask;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> track(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        
        // 1. Multi-source BFS for Pacific
        for (int i = 0; i < m; i++) {
            q.push({i, 0});
            track[i][0] |= 1;
        }
        for (int j = 1; j < n; j++) { 
            q.push({0, j});
            track[0][j] |= 1; 
        }
        // Pass references to our new helper method
        bfs(q, track, heights, 1); 
        
        // 2. Multi-source BFS for Atlantic
        for (int i = 0; i < m; i++) {
            q.push({i, n - 1});
            track[i][n - 1] |= 2;
        }
        for (int j = 0; j < n - 1; j++) {
            q.push({m - 1, j});
            track[m - 1][j] |= 2;
        }
        bfs(q, track, heights, 2); 
        
        // 3. Collect results where mask == 3
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (track[i][j] == 3) { 
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};