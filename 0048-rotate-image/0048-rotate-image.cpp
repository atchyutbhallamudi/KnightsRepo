class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Vertical Reversal (Flip upside down)
        // This swaps the top row with the bottom row, and so on.
        reverse(matrix.begin(), matrix.end());
        
        // Step 2: Transpose (Swap symmetry across the main diagonal)
        for (int i = 0; i < n; i++) {
            // j starts at i + 1 to only swap the top-right triangle 
            // with the bottom-left triangle, avoiding double-swapping
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};