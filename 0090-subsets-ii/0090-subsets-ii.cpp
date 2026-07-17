class Solution {
public:
    void subsets(vector<int>& nums, set<vector<int>>& st, vector<int>& level, int idx){
        int n=nums.size();
        if(idx==n){
            st.insert(level);
            return;
        }
        level.push_back(nums[idx]);
        subsets(nums, st, level, idx+1);
        level.pop_back();
        subsets(nums, st, level, idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        set<vector<int>> st;
        vector<int> level;
        subsets(nums, st, level, 0);
        vector<vector<int>> ans;
        for(auto& it : st){
            ans.push_back(it);
        }
        return ans;
    }
};