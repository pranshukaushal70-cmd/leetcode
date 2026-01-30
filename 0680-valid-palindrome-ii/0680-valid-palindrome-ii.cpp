class Solution {
public:
    bool ispal(string s, int l, int k){
        while(l<k){
            if(s[l] != s[k]) return false;
            l++;
            k--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st = 0;
        int end = s.size() - 1;
        while (st < end) {
            while (st < end && !isalnum(s[st])) st++;
            while (st < end && !isalnum(s[end])) end--;
            if (tolower(s[st]) != tolower(s[end])){
                return ispal(s, st + 1, end) || ispal(s, st, end-1);
            }
            st++;
            end--;
        }
        return true;
    }
};