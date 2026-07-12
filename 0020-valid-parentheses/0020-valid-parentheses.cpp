class Solution {
public:
    bool isValid(string sin) {
        unordered_map<char,int> mp;
        mp['('] = 1;
        mp[')'] = -1;
        mp['{'] = 2;
        mp['}'] = -2;
        mp['['] = 3;
        mp[']'] = -3;
        stack<int> s;
        for(auto v : sin){
            if(mp[v] > 0)s.push(mp[v]);
            else{
                if(s.empty()) return false;
                int top = s.top();
                s.pop();
                if(top + mp[v] == 0)continue;
                else return false;
            }
        }
        if(!s.empty()) return false;
        return true;
    }
};