class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);
        int i = 0;
        while (i < s.size()) {
            string word = "";
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            int pos = word.back() - '0';
            word.pop_back();
            words[pos] = word;
            i++; 
        }
        string result = "";
        for (int i = 1; i < 10; i++) {
            if (words[i] != "") {
                if (!result.empty()) result += " ";
                result += words[i];
            }
        }
        return result;
    }
};