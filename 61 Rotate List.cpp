class Solution {
    int getListSize(ListNode* head) {
        int count = 0;
        while(head != nullptr) {
            head = head->next;
            count++;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *front = head;
        ListNode *tail = head;
        int listSize = getListSize(head);
        if(listSize < 2) {
            return head;
        }
        k = k % listSize;
        if(k == 0) {
            return head;
        }
        for(int i = 0 ;i<k;i++) {
            front = front -> next;
        }

        while(front->next != nullptr) {
            front = front->next;
            tail = tail->next;
        }
        front->next = head;
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};
