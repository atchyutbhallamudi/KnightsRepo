class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0;
        unordered_map<int,int> mp;
        mp.insert({mask,-1});
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            char temp = s[i];
            if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){
                mask = mask^(1<<(s[i]-'a'));
            }
            auto it = mp.find(mask);
            if(it != mp.end())ans = max(ans,i-mp[mask]);
            else mp[mask] = i;
        }
        return ans;
    }
};