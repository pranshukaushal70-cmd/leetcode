class Solution {
public:
    string build(string s) {
        string result;
        for (char ch : s) {
            if (ch != '#') {
                result.push_back(ch);
            } else if (!result.empty()) {
                result.pop_back();
            }
        }
        return result;
    }
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};