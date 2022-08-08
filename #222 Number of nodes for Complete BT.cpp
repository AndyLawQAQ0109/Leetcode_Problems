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
    // ------------- BFS --------------------
    int countNodes(TreeNode *root){
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int ans = 1;
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left){
                ans++;
                q.push(curr->left);
            }
            if(curr->right){
                ans++;
                q.push(curr->right);
            }
        }
        return ans;
    }
    // -------------------- DFS -------------------
    // int countNodes(TreeNode* root) {
    //     if(!root) return 0;
    //     int ans = 1;
    //     dfs(root, ans);
    //     return ans;
    // }
    // void dfs(TreeNode *root, int &count){
    //     if(root->left){
    //         count++;
    //         dfs(root->left, count);
    //     }
    //     if(root->right){
    //         count++;
    //         dfs(root->right, count);
    //     }
    // }
};
