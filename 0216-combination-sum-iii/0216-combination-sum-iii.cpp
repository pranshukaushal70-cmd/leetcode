class Solution {
public:
    void combination(int k, int n, vector<vector<int>>& ans, 
                     vector<int>& level, int i, int& sum) {
        if(sum > n) return;
        if(level.size() == k){
            if(sum == n)
                ans.push_back(level);
            return;
        }
        if(i > 9) return;
        level.push_back(i);
        sum += i;
        combination(k, n, ans, level, i+1, sum);
        level.pop_back();
        sum -= i;
        combination(k, n, ans, level, i+1, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> level;
        int sum = 0;
        combination(k, n, ans, level, 1, sum);
        return ans;
    }
};