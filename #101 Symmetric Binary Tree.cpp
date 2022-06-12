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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return checkBothSides(root->left, root->right);
    }
    bool checkBothSides(TreeNode *l, TreeNode *r){
        if(!r && !l) return true;
        if((r && !l) || (!r && l)) return false;
        if(l->val != r->val) return false;
        return checkBothSides(l->right, r->left) && checkBothSides(l->left, r->right);
    }
};
