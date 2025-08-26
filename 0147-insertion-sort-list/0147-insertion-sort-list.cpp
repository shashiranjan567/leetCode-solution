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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0); // dummy before sorted list
        dummy->next = head;
        ListNode* lastSorted = head;      // end of sorted portion
        ListNode* curr = head->next;      // node to insert

        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                // Already in correct position
                lastSorted = curr;
            } else {
                // Need to insert curr in sorted portion
                ListNode* prev = dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                // Insert curr after prev
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next; // Move to next node
        }

        return dummy->next;
    }
};