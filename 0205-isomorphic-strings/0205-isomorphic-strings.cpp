class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> sToT;  
        map<char, char> tToS;  
        for(int i = 0; i < s.size(); i++){
            char sc = s[i], tc = t[i];
            if(sToT.count(sc) && sToT[sc] != tc) return false;
            if(tToS.count(tc) && tToS[tc] != sc) return false;
            sToT[sc] = tc;
            tToS[tc] = sc;
        }
        return true;
    }
};