class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* insertPosition = dummyNode;
        while(insertPosition-> next != nullptr && insertPosition->next->val < x) {
            insertPosition = insertPosition->next;
        }
        ListNode* prev = insertPosition;
        ListNode* cur = prev->next;
        while(cur != nullptr) {
            if(cur->val < x) {
                prev->next = cur->next;
                cur->next = insertPosition->next;
                insertPosition->next = cur;
                cur = prev->next;
                insertPosition = insertPosition->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummyNode->next;
    }
};
