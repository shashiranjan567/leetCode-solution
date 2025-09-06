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
//Approach - Simple Recursion
//T.C : ~O(4*n)
//S.C : O(n) system stack space because of Recursion
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL) {
            return false;
        }

        if(root1 -> val == root2->val) {
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
                   flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        }

        return false;
    }
};


