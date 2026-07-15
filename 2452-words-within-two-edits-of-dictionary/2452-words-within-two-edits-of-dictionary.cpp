class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (string &word : queries) {
            bool found = false;
            for (string &dictWord : dictionary) {
                int diff = 0;
                for (int i = 0; i < word.size(); i++) {
                    if (word[i] != dictWord[i])
                        diff++;
                    if (diff > 2)
                        break;
                }
                if (diff <= 2) {
                    found = true;
                    break;
                }
            }
            if (found)
                ans.push_back(word);
        }
        return ans;
    }
};