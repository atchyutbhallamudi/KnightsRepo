class Solution {
public:
    bool isPalindrome(int x) {
        string temp = to_string(x);
        string temp1 = temp;
        reverse(temp.begin(),temp.end());
        for(int i = 0;i<temp.size();i++) if(temp[i]!=temp1[i]) return false;
        return true;
    }
};