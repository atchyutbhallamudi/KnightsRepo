class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        // Define our four boundaries
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Move RIGHT along the top boundary
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Shrink top boundary down
            
            // 2. Move DOWN along the right boundary
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Shrink right boundary left
            
            // 3. Move LEFT along the bottom boundary (if still valid)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Shrink bottom boundary up
            }
            
            // 4. Move UP along the left boundary (if still valid)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Shrink left boundary right
            }
        }
        
        return ans;
    }
};