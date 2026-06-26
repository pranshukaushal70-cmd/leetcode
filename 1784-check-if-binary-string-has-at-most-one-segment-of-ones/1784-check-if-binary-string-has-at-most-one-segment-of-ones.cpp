class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i == 0 || s[i-1] == '0') count++;
            }
        }
        return count == 1;
    }
};