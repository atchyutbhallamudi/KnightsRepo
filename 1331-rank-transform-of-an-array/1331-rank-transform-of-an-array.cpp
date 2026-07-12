class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> myset(arr.begin(), arr.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : myset) {
            rank[x] = r++;
        }

        for (int& x : arr) {
            x = rank[x];
        }

        return arr;
    }
};