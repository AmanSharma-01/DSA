class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        int c=0;
        
        for(int i=0;i<n;i++) {
            st.push(pushed[i]);
            while(!st.empty() && popped[c]==st.top()) {
                st.pop();
                c++;
            }
        }
        
        return st.empty();
    }
};