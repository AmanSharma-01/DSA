class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        int n = ast.size();
        
        for(int i=0;i<n;i++) {
            if(ast[i] > 0 || st.empty()) {
                st.push(ast[i]);
            } else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(ast[i])) {
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(ast[i])) {
                    st.pop();
                } else {
                    if(st.empty() || st.top() < 0) {
                        st.push(ast[i]);
                    }
                }
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};