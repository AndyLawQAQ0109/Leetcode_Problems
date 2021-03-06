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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        // if(!root->left){
        //     root->left = root->right;
        //     root->right = nullptr;
        //     invertTree(root->left);
        // }
        // else if(!root->right){
        //     root->right = root->left;
        //     root->left = nullptr;
        //     invertTree(root->right);
        // }
        // else{
        //     TreeNode *tmp = root->left;
        //     root->left = root->right;
        //     root->right = tmp;
        //     invertTree(root->left);
        //     invertTree(root->right);
        // }
        TreeNode *l = invertTree(root->right);
        TreeNode *r = invertTree(root->left);
        root->left = l;
        root->right = r;
        return root;
    }
};
