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
    int lastNodeCompared = INT_MIN;
    bool lastNodeInitialized = false;
    bool isValid(TreeNode* node) {
        if(node == nullptr)
            return true;
        bool res = isValid(node->left);
        if(lastNodeInitialized) {
            res = res && node->val > lastNodeCompared;
        }
        if(!res)
            return false;
        lastNodeInitialized = true;
        lastNodeCompared = node->val;
        return res && isValid(node->right);
    }
    
    
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root);
    }
};