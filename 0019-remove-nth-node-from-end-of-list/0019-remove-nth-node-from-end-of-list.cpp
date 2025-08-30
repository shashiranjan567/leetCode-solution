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

//FROM MYSELF
//Approach-1 (2 Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    
    int lengthLinkedList(ListNode* head) {
        int l = 0;
        
        while(head) {
            l++;
            head = head->next;
        }
        return l;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = lengthLinkedList(head);
        
        if(length == n) { //Length node form end means first node
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        int travel = length-n;
        
        while(travel--) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        
        delete(temp);   
        
        return head;
        
    }
};

/*//Approach-2 (1 Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i = 1; i <= n; i++) {
            fast = fast->next;
        }
        if(fast == NULL) {
            return head->next;
        }
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
};*/

/*class Solution {
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
};*/