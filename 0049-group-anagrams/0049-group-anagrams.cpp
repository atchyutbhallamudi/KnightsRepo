class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to group the anagrams. 
        // Key = 26-character frequency string, Value = list of original strings
        unordered_map<string, vector<string>> mp;
        
        for (string s : strs) {
            // Create a string of length 26, initialized with null characters (value 0)
            // This acts exactly like an array of 26 integers, but works perfectly as a hash key!
            string key(26, 0); 
            
            // Count the frequency of each character in the current word
            for (char c : s) {
                key[c - 'a']++; 
            }
            
            // Push the original string into the bucket for this specific frequency key
            mp[key].push_back(s);
        }
        
        // Prepare the final answer by extracting the grouped lists from the map
        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};