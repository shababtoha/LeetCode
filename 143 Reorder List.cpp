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
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> q;
        while(head != nullptr) {
            q.push_back(head);
            head = head->next;
        }
        ListNode* node = new ListNode(-1);
        head = node;
        bool front = true;
        while(!q.empty()) {
            if(front) {
                node->next = q.front();
                q.pop_front();
            } else {
                node->next = q.back();
                q.pop_back();
            }
            node=node->next;
            front ^= 1;
        }
        node->next = nullptr;
        head = head->next;
    }
};