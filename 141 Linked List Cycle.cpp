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
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        ListNode *hare = head;
        ListNode *tortoise = head;
        do {
            if(hare->next == nullptr || hare->next->next == nullptr)
                return false;
            hare = hare->next->next;
            tortoise = tortoise->next;
        } while(hare != tortoise);
        return true;
    }
};