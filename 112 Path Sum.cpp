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
    bool hasPathSum(TreeNode* root, int targetSum, int currentSum) {
        if(root == nullptr)
            return false;
        if(root->right == nullptr && root->left == nullptr && currentSum  + root->val == targetSum)
            return true;
        return hasPathSum(root->left, targetSum, currentSum +  + root->val) | 
            hasPathSum(root->right, targetSum, currentSum +  + root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(root, targetSum, 0);
    }
};