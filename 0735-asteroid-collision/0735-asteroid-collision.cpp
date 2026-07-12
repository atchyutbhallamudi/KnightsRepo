class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(a[i] > 0) {
                st.push(a[i]);
            } else {
                while(!st.empty() && st.top() < -a[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    ans.push_back(a[i]);
                } else if(st.top() == -a[i]) {
                    st.pop();
                }
            }         
        }
        
        vector<int> t;
        while(!st.empty()) {
            t.push_back(st.top());
            st.pop();
        }
        
        for(int i = t.size() - 1; i >= 0; i--) {
            ans.push_back(t[i]);
        }

        return ans;
    }
};