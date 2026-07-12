#include <stack>
#include <algorithm>

class MinStack {
private:
    // Stack stores pairs of {actual_value, current_minimum}
    std::stack<std::pair<int, int>> st;

public:
    MinStack() {
        // Constructor can stay empty, std::stack initializes itself
    }
    
    void push(int value) {
        if (st.empty()) {
            // If it's the first element, it is the minimum by default
            st.push({value, value});
        } else {
            // Compare the new value with the current minimum at the top of the stack
            int current_min = std::min(value, st.top().second);
            st.push({value, current_min});
        }
    }
    
    void pop() {
        // std::stack pop doesn't return anything, just removes the top
        st.pop();
    }
    
    int top() {
        // The actual value is the first element of the pair
        return st.top().first;
    }
    
    int getMin() {
        // The minimum so far is the second element of the pair
        return st.top().second;
    }
};