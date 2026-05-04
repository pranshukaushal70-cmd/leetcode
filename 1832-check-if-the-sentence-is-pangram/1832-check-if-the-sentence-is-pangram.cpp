class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;

        for(char ch : sentence) {
            if(ch >= 'a' && ch <= 'z') {
                st.insert(ch);
            }
        }
        return st.size() == 26;
    }
};