class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto v : asteroids){
            if(v>0 || st.empty())st.push(v);
            else{
                st.push(v);
                while(st.size() > 1 && st.top() < 0){
                    int top = st.top();
                    st.pop();
                    int topb = st.top();
                    if(topb < 0){
                        st.push(top);
                        break;
                    }
                    st.pop();
                    if(abs(top) == abs(topb)) continue;
                    else if(abs(top) > abs(topb)) st.push(top);
                    else st.push(topb);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};