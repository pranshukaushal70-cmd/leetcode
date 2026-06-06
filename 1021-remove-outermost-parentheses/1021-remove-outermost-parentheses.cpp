class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                char a = st.top();
                st.pop();
            }
            if(!st.empty()) ans.push_back(s[i]);
            if(s[i] == '(') st.push(s[i]);
        }
        return ans;
    }
};