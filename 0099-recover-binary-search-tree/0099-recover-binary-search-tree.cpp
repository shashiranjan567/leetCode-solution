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
    TreeNode* firstStartPoint = NULL;
    TreeNode* lastEndPoint    = NULL;
    TreeNode* prev            = NULL;
    void inOrder(TreeNode* root) {
        if(!root)
            return;
        inOrder(root->left);
        
        if(prev != NULL && prev->val > root->val) {
            if(firstStartPoint == NULL) {
                firstStartPoint = prev;
            }
            lastEndPoint = root;
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        
        inOrder(root);
        if(firstStartPoint && lastEndPoint)
            swap(firstStartPoint->val, lastEndPoint->val);
    }
};