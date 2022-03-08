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
    
    ListNode* reverse(ListNode* prev, ListNode* cur, int left, int right) {
        if(left > right) {
            return cur;
        }
        ListNode* last = reverse(cur, cur->next, left+ 1, right);
        cur->next = prev;
        return last;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(INT_MIN, head);
        ListNode* prevNodeOfReverse = dummyNode;
        ListNode* nextNodeOfReverse = head;
        int i = 0;
        while(nextNodeOfReverse != nullptr) {
            i++;
            if(i < left)
                prevNodeOfReverse = prevNodeOfReverse->next;
            if(i == right)
                break;
            nextNodeOfReverse = nextNodeOfReverse->next;
            
        }
        ListNode* last = reverse(nullptr, prevNodeOfReverse->next, left, right);
        prevNodeOfReverse->next->next = last; 
        prevNodeOfReverse->next = nextNodeOfReverse;
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};