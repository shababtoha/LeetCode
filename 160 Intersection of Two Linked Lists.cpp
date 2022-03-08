/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLinkedListSize(ListNode* head) {
        int sz = 0;
        while(head != nullptr) {
            head = head->next;
            sz++;
        };
        return sz;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int szA = getLinkedListSize(headA);
        int szB = getLinkedListSize(headB);
        while(szB > szA) {
            szB--;
            headB = headB->next;
        }
        while(szA > szB) {
            szA--;
            headA = headA->next;
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};