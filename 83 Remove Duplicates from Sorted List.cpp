#include<iostream>
#include<stdlib.h>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head-> next == nullptr) {
            return head;
        }
        ListNode* prev = head;
        ListNode* cur = prev->next;
        while(cur != nullptr) {
            if(cur->val == prev->val) {
                ListNode* deleted = cur;
                prev->next = cur->next;
                cur = cur->next;
                free(deleted);
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main() {


}
