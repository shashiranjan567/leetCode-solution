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
    ListNode* mergeSortedList(ListNode* head1, ListNode* head2) {
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        
        while(head1 && head2) {
            if(head1->val > head2->val) {
                temp->next = head2;
                head2 = head2->next;
            } else {
                temp->next = head1;
                head1 = head1->next;
            }
            temp = temp->next;
        }
        if(head1)
            temp->next = head1;
        else
            temp->next = head2;
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) {
            prev->next = NULL;
        }
        
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(slow);
        
        return mergeSortedList(list1, list2);
    }
};

/*class Solution {
public:
    ListNode* sortList(ListNode* head) {
        while (--n && head) head = head->next;
        if (!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }

    // Helper to merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev) {
        ListNode* curr = prev;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        while (curr->next) curr = curr->next; // move to end
        return curr; // return tail
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: find length
        int length = 0;
        for (ListNode* p = head; p; p = p->next) length++;

        ListNode dummy(0);
        dummy.next = head;

        // Step 2: bottom-up merge sort
        for (int size = 1; size < length; size <<= 1) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);

                prev = merge(left, right, prev);
            }
        }

        return dummy.next;
    }
};
*/