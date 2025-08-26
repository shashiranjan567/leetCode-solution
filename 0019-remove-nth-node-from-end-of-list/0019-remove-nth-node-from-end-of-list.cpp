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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node before head to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n+1 steps ahead so gap is n
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move both until first reaches end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Now second points to (n+1)th node from end
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        return dummy->next;
    }
};