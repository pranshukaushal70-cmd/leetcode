class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> p;
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto& it : mp) p.push({it.second, it.first});
        while(!p.empty() && ans.size()<k){
            auto temp=p.top();
            p.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};