/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postordernary(Node* root, vector<int> &result){
        if(root==NULL) return;
        for(Node* child : root->children){
            postordernary(child, result);
        }
        result.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        postordernary(root, result);
        return result;
    }
};