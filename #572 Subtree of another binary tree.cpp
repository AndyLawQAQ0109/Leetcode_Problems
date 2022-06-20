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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            if(curr->val == subRoot->val){
                bool res = bfs(curr, subRoot);
                if(res) return true;
            }
        }
        return false;
    }
    bool bfs(TreeNode *root, TreeNode *subRoot){
        if(!root && !subRoot) return true;
        else if(!root || !subRoot) return false;
        if(root->val == subRoot->val)
            return bfs(root->left, subRoot->left) && bfs(root->right, subRoot->right);
        return false;
    }
};
