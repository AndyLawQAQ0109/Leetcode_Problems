/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(p == root || q == root || !root)
        //     return root;
        // TreeNode *l = lowestCommonAncestor(root->left, p, q);
        // TreeNode *r = lowestCommonAncestor(root->right, p, q);

        // if(!l) return r;
        // if(!r) return l;
        // return root;
        if(p == root || q == root)
            return root;
        if(find(root->left, p) && find(root->left, q)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(find(root->right, p) && find(root->right, q)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    bool find(TreeNode *root, TreeNode *n){
        if(!root) 
            return false;
        if(root == n)
            return true;
        return find(root->left, n) || find(root->right, n);
    }
};
