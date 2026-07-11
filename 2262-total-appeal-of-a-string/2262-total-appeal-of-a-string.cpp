class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        long long n = s.length();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int last = -1;
            long long contrib = (n * (n + 1)) / 2;
            for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    long long len = i - last;
                    contrib -= (len * (len - 1)) / 2;
                    last = i;
                }
            }
            long long len = n - last - 1;
            contrib -= (len * (len + 1)) / 2;
            ans += contrib;
        }
        return ans;
    }
};