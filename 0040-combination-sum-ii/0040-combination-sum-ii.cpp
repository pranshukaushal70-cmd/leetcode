class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx,
                vector<vector<int>>& ans, vector<int>& level) {
        if (target == 0) {
            ans.push_back(level);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i-1])
                continue;
            if (candidates[i] > target)
                break;
            level.push_back(candidates[i]);
            helper(candidates, target - candidates[i],
                   i + 1, ans, level);
            level.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> level;
        helper(candidates, target, 0, ans, level);
        return ans;
    }
};