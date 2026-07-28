class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        string half = "";
        char mid = '\0';
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                mid = 'a' + i;   
            }
            half += string(freq[i] / 2, 'a' + i);  
        }
        string result = half;
        if (mid != '\0') result += mid;
        result += string(half.rbegin(), half.rend());  
        return result;
    }
};