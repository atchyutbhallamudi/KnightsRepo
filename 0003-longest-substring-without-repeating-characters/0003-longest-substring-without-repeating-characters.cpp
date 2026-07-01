class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> hash;
        int head = -1;
        int tail = 0;
        int ans = 0;
        int n = s.size();
        while(tail < n){
            int count = 0;
            while(head + 1 < n && hash[s[head+1]-'a'] == 0){
                hash[s[head+1]-'a']++;
                head++;
            }
            count = head-tail+1;
            ans = max(count, ans);

            if(tail <=head){
                hash[s[tail]-'a']--;
                tail++;
            }
            else{
                hash[s[tail]-'a']--;
                tail++;
                head = tail -1;
            }
        }
        return ans;
    }
};