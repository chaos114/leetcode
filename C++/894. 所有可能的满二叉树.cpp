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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if(N == 1){
            TreeNode* root = new TreeNode(0);
            res.push_back(root);
            return res;
        }
        else{
           for(int i = 1;i < N;i+=2){
             for(auto left: allPossibleFBT(i))
                    for(auto right:allPossibleFBT(N-i-1))
                    {
                        TreeNode * root = new TreeNode(0);
                        root->left =left;
                        root->right =right;
                        res.push_back(root);
                    }
            
        } 
        
        
        return res;
    }
    }
};