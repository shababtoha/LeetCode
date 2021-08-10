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
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> currentLevelNodes;
        if(root == nullptr) {
            return ans;
        }
        int processingLevel = 1;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 1});
        while(!q.empty()) {
            TreeNode* currentNode = q.front().first;
            int currentLevel = q.front().second;
            q.pop();
            if(currentLevel > processingLevel ) {
                processingLevel++;
                ans.push_back(currentLevelNodes);
                currentLevelNodes.clear();
            }
            if(currentNode != nullptr) {
                currentLevelNodes.push_back(currentNode->val);
                q.push({currentNode->left, currentLevel + 1});
                q.push({currentNode->right, currentLevel + 1});
            }
        }
           
        return ans;
    }
};