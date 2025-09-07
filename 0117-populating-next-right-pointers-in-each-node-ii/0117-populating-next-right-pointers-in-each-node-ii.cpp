/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/*
//ITERATIVE solution
class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;
        
        while(head) {
            Node* next_level_head = NULL;
            Node* next_level_curr = NULL;
            //we will try to connect links of next level while
            //travelling in current level like linked list
            while(head) {
                if(head->left) {
                    if(!next_level_curr) {
                        next_level_head = next_level_curr = head->left;
                    } else {
                        next_level_curr->next = head->left;
                        next_level_curr       = next_level_curr->next;
                    }
                }
                
                if(head->right) {
                    if(!next_level_curr) {
                        next_level_head = next_level_curr = head->right;
                    } else {
                        next_level_curr->next = head->right;
                        next_level_curr       = next_level_curr->next;
                    }
                }
                head = head->next;
            }
            head = next_level_head;
        }
        
        return root;
    }
};
*/

//RECURSIVE solution
class Solution {
public:
    void helper(Node* root) {
        if(!root)
            return;
        
        Node* curr = root;
        Node* nextLevel = new Node();
        Node* prev = nextLevel;
        while(curr) {
            if(curr->left) {
                prev->next = curr->left;
                prev = prev->next;
            }
            if(curr->right) {
                prev->next = curr->right;
                prev = prev->next;
            }
            curr = curr->next;
        }
        helper(nextLevel->next);
    }
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};