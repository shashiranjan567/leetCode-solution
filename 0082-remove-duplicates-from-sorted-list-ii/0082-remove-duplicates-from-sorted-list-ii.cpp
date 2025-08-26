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
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy; // prev is the last node before the duplicates

        while (head != nullptr) {
            // If we found duplicates
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with this value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Link prev to node after duplicates
                prev->next = head->next;
            } else {
                // No duplicate, move prev
                prev = prev->next;
            }
            head = head->next; // move forward
        }

        return dummy->next;
    }
};