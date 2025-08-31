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
//Approach-1 (Using stack)
//T.C  : O(n)
//S.C  : O(n)
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* current = head;

        while (current != nullptr) {
            st.push(current);
            current = current->next;
        }

        current = st.top();
        st.pop();
        int maximum = current->val;
        ListNode* resultHead = new ListNode(maximum);

        while (!st.empty()) {
            current = st.top();
            st.pop();
            if (current->val < maximum) {
                continue;
            }
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultHead;
                resultHead = newNode;
                maximum = current->val;
            }
        }

        return resultHead;
    }
};


/*
//Approach-2 (Using Recursion - instead of stack, use system's stack)
//T.C : O(n)
//S.C : O(n) system stack
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Base case: If the list is empty or has only one node, return it as is
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Recursively process the next node
        ListNode* nextNode = removeNodes(head->next);

        // If the current node's value is less than the next node's value, skip it
        if (head->val < nextNode->val) {
            return nextNode;
        }

        // Otherwise, retain the current node and link it to the modified next node
        head->next = nextNode;
        return head;
    }
};
*/

/*
//Approach-3 (Using reverse)
//T.C : O(n)
//S.C : O(1)
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return last;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        int maximum = 0;
        ListNode* prev = NULL;
        ListNode* current = head;

        while (current != NULL) {
            maximum = max(maximum, current->val);

            if (current->val < maximum) {
                if (prev == NULL) {
                    // we're deleting the head of the list
                    head = current->next;
                    current = head;
                } else {
                    prev->next = current->next;
                    current = current->next;
                }
            }

            else {
                prev = current;
                current = current->next;
            }
        }
        
        return reverseList(head);
    }
};
*/