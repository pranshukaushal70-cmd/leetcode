class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int a : nums){
            mp[a]++;
        }
        for(auto& b : mp){
            if(b.second==1) ans.push_back(b.first);
        }
        return ans;
    }
};