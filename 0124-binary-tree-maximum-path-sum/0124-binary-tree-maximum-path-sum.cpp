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
    int ans=INT_MIN;
    int maxsum(TreeNode* root){
        if(root == NULL) return 0;
        int leftval=max(0, maxsum(root->left));
        int rightval=max(0, maxsum(root->right));
        ans=max(ans, leftval+rightval+root->val);
        return root->val + max(rightval, leftval);
    }
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return ans;
    }
};