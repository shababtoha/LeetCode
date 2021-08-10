class Solution {
    bool isDeleted;
    ListNode* deleteAllNodeWithCurrentValue(ListNode* cur) {
        if(cur == nullptr) {
            return nullptr;
        }
        int val = cur->val;
        int cnt = 0;
        while(cur != nullptr && val == cur->val) {
            cur = cur->next;
            cnt++;
        }
        isDeleted = (cnt > 1);
        return cur;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        while(cur != nullptr) {
            isDeleted = false;
            ListNode* nextNumber = deleteAllNodeWithCurrentValue(cur->next);
            if(nextNumber == nullptr) {
                if(isDeleted) {
                    cur->next = nullptr;
                }
                break;
            }
            if(!isDeleted) {
                cur = cur->next;
            } else {
                cur->next = nextNumber;
            }
        }
        return dummyNode->next;
    }
};
