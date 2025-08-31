/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //Time : O(n), we visit each node only once
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small  = new ListNode(0);
        ListNode* large  = new ListNode(0);
        
        ListNode* smallP = small;
        ListNode* largeP = large;
        
        while(head) {
            if(head->val < x) {
                smallP->next = head;
                smallP = smallP->next;
            } else {
                largeP->next = head;
                largeP = largeP->next;
            }
            
            head = head->next;
        }
        
        largeP->next = NULL;
        smallP->next = large->next;
        return small->next;
    }
};
/*class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads for two lists
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);
        
        // Pointers to build two lists
        ListNode* before = beforeHead;
        ListNode* after = afterHead;
        
        while (head != nullptr) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        // End 'after' list
        after->next = nullptr;
        
        // Merge two lists
        before->next = afterHead->next;
        
        return beforeHead->next;
    }
};

*/