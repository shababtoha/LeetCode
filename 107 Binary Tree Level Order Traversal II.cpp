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
    
    vector<vector<int> > bfs(TreeNode* root) {
        queue<pair<TreeNode* ,int> > q;
        q.push({root, 1});
        vector<vector<int>> ans;
        vector<int> v;
        int curLevel = 1;
        while(!q.empty()) {
            TreeNode* currentNode = q.front().first;
            int currentLevel = q.front().second;
            q.pop();
            if(curLevel != currentLevel) {
                ans.push_back(v);
                v.clear();
                curLevel++;
            }
            v.push_back(currentNode->val);
            if(currentNode->left != nullptr) {
                q.push({currentNode->left, currentLevel + 1});
            }
            if(currentNode->right != nullptr) {
                q.push({currentNode->right, currentLevel + 1});
            }
        }
        ans.push_back(v);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if(root != nullptr) 
            ans= bfs(root);
        return ans;
    }
};