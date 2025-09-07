/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Approach-1 (Recursive) Time : O(N) worst case : skewed BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        
        //we need to find the first bifurcation point
        /*
            i.e the point just after which path for p and q separates to left and right
        */
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};

/*
//Approach-2 (Iterative) Time : O(N) worst case : skewed BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        
        while(true) {
            if(p->val < curr->val && q->val < curr->val)
                curr = curr->left;
            else if(p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            else
                break;
        }
        
        return curr;
    }
};
*/