class Solution {
public:
    #define F first
    #define S second
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        
        int count = n * m;
        pair<int,int> curr = {0,0};
 
        ans.push_back(matrix[curr.F][curr.S]);
        vis[curr.F][curr.S] = 1;
        count--;
        
        while(count > 0){
            // 1. Move RIGHT (curr.S + 1)
            while(isValid(curr.F, curr.S + 1, n, m) && vis[curr.F][curr.S + 1] != 1){
                curr.S++;
                ans.push_back(matrix[curr.F][curr.S]);
                vis[curr.F][curr.S] = 1;
                count--;
            }
            
            // 2. Move DOWN (curr.F + 1)
            while(isValid(curr.F + 1, curr.S, n, m) && vis[curr.F + 1][curr.S] != 1){
                curr.F++;
                ans.push_back(matrix[curr.F][curr.S]);
                vis[curr.F][curr.S] = 1;
                count--;
            }
            
            // 3. Move LEFT (curr.S - 1)
            while(isValid(curr.F, curr.S - 1, n, m) && vis[curr.F][curr.S - 1] != 1){
                curr.S--;
                ans.push_back(matrix[curr.F][curr.S]);
                vis[curr.F][curr.S] = 1;
                count--;
            }
            
            // 4. Move UP (curr.F - 1)
            while(isValid(curr.F - 1, curr.S, n, m) && vis[curr.F - 1][curr.S] != 1){
                curr.F--;
                ans.push_back(matrix[curr.F][curr.S]);
                vis[curr.F][curr.S] = 1;
                count--;
            }
        }
        return ans;
    }
};