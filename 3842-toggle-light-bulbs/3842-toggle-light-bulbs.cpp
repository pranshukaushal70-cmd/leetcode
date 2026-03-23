class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto it:bulbs){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second%2==1) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};