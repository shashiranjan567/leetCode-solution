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
    int maxDiff = INT_MIN;
    int findMaxDiff(TreeNode* root, int min_v, int max_v) {
        if(!root)
            return (max_v - min_v);
        
        maxDiff = max(maxDiff, abs(root->val - min_v));
        maxDiff = max(maxDiff, abs(root->val - max_v));
        
        min_v = min(min_v, root->val);
        max_v = max(max_v, root->val);
        
        int l = findMaxDiff(root->left, min_v, max_v);
        int r = findMaxDiff(root->right, min_v, max_v);
        
        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = INT_MIN;
        findMaxDiff(root, root->val, root->val);
        
        return maxDiff;
    }
};