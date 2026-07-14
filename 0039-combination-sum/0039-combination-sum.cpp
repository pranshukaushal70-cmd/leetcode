class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx,
                vector<vector<int>>& ans, vector<int> level, int sum) {
        if (sum == target) {
            ans.push_back(level);
            return;
        }
        if (idx == candidates.size() || sum > target)
            return;
        level.push_back(candidates[idx]);
        sum += candidates[idx];
        helper(candidates, target, idx , ans, level, sum);
        level.pop_back();
        sum -= candidates[idx];
        helper(candidates, target, idx + 1, ans, level, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> level;
        int sum = 0;
        int idx=0;
        helper(candidates, target, idx, ans, level, sum);
        return ans;
    }
};