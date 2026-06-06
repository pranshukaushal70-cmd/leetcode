class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string doubled = s + s;
        int pos = doubled.find(goal);
        if(pos != -1) return true;
        return false;
    }
};