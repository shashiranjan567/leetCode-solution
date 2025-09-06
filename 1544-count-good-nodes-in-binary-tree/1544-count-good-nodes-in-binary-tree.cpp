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
    int count = 0;
    void dfs(TreeNode* root, int val) {
        if(!root)
            return;
        
        if(root->val >= val)
            count++;
        
        dfs(root->left,  max(root->val, val));
        dfs(root->right, max(root->val, val));
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        dfs(root, root->val);
        return count;
    }
};