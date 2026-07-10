class Solution {
public:
    int longestAwesome(string s) {
        // Since there are only 10 digits, the mask ranges from 0 to 1023.
        // Initialize an array of size 1024 with -2 (indicating "unvisited").
        vector<int> mp(1024, -2);
        
        // Base case: at index -1, the mask is 0 (all digits have even frequencies)
        mp[0] = -1;
        
        int mask = 0;
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++){
            // Flip the bit corresponding to the current digit
            mask ^= (1 << (s[i] - '0'));
            
            // Case 1: All characters in the substring have an even frequency
            // (The exact mask has been seen before)
            if(mp[mask] != -2) {
                ans = max(ans, i - mp[mask]);
            }
            
            // Case 2: Exactly one character has an odd frequency
            // (The mask differs by exactly 1 bit from a previously seen mask)
            for(int j = 0; j < 10; j++){
                int target_mask = mask ^ (1 << j);
                if(mp[target_mask] != -2) {
                    ans = max(ans, i - mp[target_mask]);
                }
            }
            
            // Save the earliest index for this mask to maximize substring length
            if(mp[mask] == -2) {
                mp[mask] = i;
            }
        }
        
        return ans;
    }
};