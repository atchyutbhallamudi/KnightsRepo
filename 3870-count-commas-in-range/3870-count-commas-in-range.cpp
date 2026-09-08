class Solution {
public:
    int countCommas(int n) {
        if(n <= 999) return 0;
        if(n <= 99999) return n-1000+1;
        return 99001;
    }
};