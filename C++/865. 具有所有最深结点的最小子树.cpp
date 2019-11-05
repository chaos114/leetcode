/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).second;
    }
    pair<int,TreeNode*> depth(TreeNode* root){
        if(root == nullptr) return {0,nullptr};
        auto l = depth(root->left);
        auto r = depth(root->right);
        return {max(l.first,r.first) + 1,l.first == r.first ? root : l.first > r.first ? l.second : r.second};
    }
    
};