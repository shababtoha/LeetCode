/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return NULL;
        ListNode *hare = head;
        ListNode *tortoise = head;
        while(true) {
            if(hare->next == nullptr || hare->next->next == nullptr) {
                return NULL;
            }
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(hare == tortoise)
                break;
        }
        hare = head;
        while(hare != tortoise) {
            hare = hare->next;
            tortoise = tortoise->next;
        }
        return hare;
    }
};