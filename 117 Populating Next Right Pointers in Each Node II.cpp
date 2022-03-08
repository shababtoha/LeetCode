/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    
    void bfs(Node* root) {
        queue<pair<Node* ,int> > q;
        q.push({root, 1});
        while(!q.empty()) {
            Node* currentNode = q.front().first;
            int currentLevel = q.front().second;
            q.pop();
            if(!q.empty() && q.front().second == currentLevel) {
                currentNode->next = q.front().first;
            }
            if(currentNode->left != NULL) {
                q.push({currentNode->left, currentLevel + 1});
            }
            if(currentNode->right != NULL) {
                q.push({currentNode->right, currentLevel + 1});
            }
        }
    }
    
public:
    Node* connect(Node* root) {
        if(root != NULL) {
            bfs(root);
        }
        return root;
    }
};