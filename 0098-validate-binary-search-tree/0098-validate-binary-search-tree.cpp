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
    bool isBST(TreeNode* root, TreeNode* l, TreeNode* r) {
        if(!root)
            return true;
        if(l && root->val <= l->val)
            return false;
        if(r && root->val >= r->val)
            return false;
        
        if(!isBST(root->left, l, root) || !isBST(root->right, root, r))
            return false;
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        return isBST(root, l, r);  
    }
};