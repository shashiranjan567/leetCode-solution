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
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* newHead = new ListNode(-1);
        ListNode* curr    = head;
        while(curr) {
            ListNode* prev    = newHead;
            ListNode* nxt     = newHead->next;
            while(nxt) {
                if(curr->val < nxt->val)
                    break;
                prev = nxt;
                nxt = nxt->next;
            }
            
            //Simple example to understand the steps below :
            //Think about [1 , 2 , 4, 3]
            //curr = 3
            //nxt  = 4
            //prev = 2
            ListNode* temp = curr->next; //storing for curr next iteration
            curr->next     = nxt;   //3->4
            prev->next     = curr;  //2->3
            curr = temp;
        }
        return newHead->next;
    }
};