/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> freq;
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = left + right + root->val;
        freq[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == nullptr)
            return {};
        dfs(root);
        int maxFreq = 0;
        for (auto &it : freq)
            maxFreq = max(maxFreq, it.second);
        vector<int> ans;
        for (auto &it : freq) {
            if (it.second == maxFreq)
                ans.push_back(it.first);
        }
        return ans;
    }
};