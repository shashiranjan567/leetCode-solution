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
    void populate(TreeNode* root, vector<vector<int>>& result, int level) {
        queue<TreeNode*> que;
        que.push(root);
        bool alternate = false;
        while(!que.empty()) {
            int n = que.size();
            alternate = !alternate;
            vector<int> temp;
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                if(alternate)
                    temp.push_back(curr->val);
                else
                    temp.insert(temp.begin(), curr->val);
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            result.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        populate(root, result, 0);
        return result;
    }
};