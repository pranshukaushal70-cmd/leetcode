class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
        }
        vector<pair<int, char>> v;
        for(auto it : freq){
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), greater<pair<int,char>>());
        string ans = "";
        for(auto it : v){
            ans += string(it.first, it.second);
        }
        return ans;
    }
};