class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < s.length(); j++) {
                freq[s[j]]++;
                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                for (auto& p : freq) {
                    maxFreq = max(maxFreq, p.second);
                    minFreq = min(minFreq, p.second);
                }
                totalBeauty += maxFreq - minFreq;
            }
        }
        return totalBeauty;
    }
};