class Solution {
public:
    string removeOccurrences(string s, string part) {
       while(s.length() > 0 && s.find(part) < s.length()){
        int pos=s.find(part);
        s.erase(pos, part.length());
       }
       return s;
    }
};