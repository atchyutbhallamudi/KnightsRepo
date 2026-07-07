class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        stack<int> s;
        long long sum = 0;
        while(n>0){
            if(n%10)s.push(n%10);
            sum+=n%10;
            n = n/10;
        }
        string ans;
        while(!s.empty()){
            ans+=(s.top() + '0');
            s.pop();
        }
        return sum*stoll(ans);
    }
};