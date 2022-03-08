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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode* node;
    int listNodeCount(ListNode* head) {
        int cnt = 0;
        while(head != nullptr) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    TreeNode* getNewNode() {
        TreeNode* treeNode =  new TreeNode(node->val);
        node = node->next;
        return treeNode;
    }
    
    
    TreeNode* makeTree(int nodeCnt) {
        if(nodeCnt == 0)
            return nullptr;
        int mid = nodeCnt / 2;
        TreeNode* leftNode = makeTree(nodeCnt / 2);
        TreeNode* currentNode = getNewNode();
        TreeNode* rightNode = makeTree(nodeCnt-nodeCnt/2-1);
        currentNode->left = leftNode;
        currentNode->right = rightNode;
        return currentNode;
    }
    
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        node = head;
        int nodeCount = listNodeCount(head);
        return makeTree(nodeCount);
    }
};