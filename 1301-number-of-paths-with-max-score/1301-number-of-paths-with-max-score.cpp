class Solution {
    private:
        int N;
        int MOD = 1e9 + 7;
        // memo[r][c] will store a pair: {max_score, path_count}
        vector<vector<pair<int, int>>> memo;

        pair<int, int> dp(int r, int c, vector<string>& board) {
            // 1. Base Case: Reached the target destination 'E' at (0, 0)
            if (r == 0 && c == 0) {
                return {0, 1};
            }
            
            // 2. Out of bounds or hit an obstacle 'X'
            if (r < 0 || c < 0 || board[r][c] == 'X') {
                return {-1, 0}; // Use -1 score to mark an invalid path
            }
            
            // 3. Return cached result if we've already computed it
            if (memo[r][c].first != -2) {
                return memo[r][c];
            }
            
            int max_score = -1;
            int path_count = 0;
            
            // Look at the 3 valid directions we could have come from: Up, Left, Diagonal Up-Left
            int dr[] = {-1, 0, -1};
            int dc[] = {0, -1, -1};
            
            for (int i = 0; i < 3; ++i) {
                auto [next_score, next_count] = dp(r + dr[i], c + dc[i], board);
                
                if (next_score != -1) {
                    if (next_score > max_score) {
                        // Found a strictly better path score
                        max_score = next_score;
                        path_count = next_count;
                    } else if (next_score == max_score) {
                        // Found an alternative path with the exact same maximum score
                        path_count = (path_count + next_count) % MOD;
                    }
                }
            }
            
            pair<int, int> res;
            // If at least one valid path exists, add the current cell's value
            if (max_score != -1) {
                int current_val = (board[r][c] != 'S') ? (board[r][c] - '0') : 0;
                res = {max_score + current_val, path_count};
            } else {
                res = {-1, 0};
            }
            
            return memo[r][c] = res;
        }

    public:
        vector<int> pathsWithMaxScore(vector<string>& board) {
            N = board.size();
            
            // Initialize memo table with {-2, 0} to represent unvisited states
            memo.assign(N, vector<pair<int, int>>(N, {-2, 0}));
            
            // Start the recursion from the bottom-right corner 'S'
            auto [max_score, path_count] = dp(N - 1, N - 1, board);
            
            // If no valid path to 'E' exists, return {0, 0}
            if (max_score == -1) {
                return {0, 0};
            }
            
            return {max_score, path_count};
        }
};