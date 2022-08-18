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
    void flatten(TreeNode* root) {
        if(!root)
            return;

        TreeNode *rightMost = root->left; // rightmost node of left subtree
        if(!root->right){ // right is empty
            root->right = root->left;
            root->left = nullptr;
        }
        else if(rightMost){ // right is not empty && left is not empty
            while(rightMost->right){
                rightMost = rightMost->right;
            }
            // ------ Don't need to care about left, only consider right most ---------
            // while(rightMost->left || rightMost->right){
            //     if(rightMost->right)
            //         rightMost = rightMost->right;
            //     else
            //         rightMost = rightMost->left;
            // }
            
            TreeNode *tmp = root->right;
            root->right = root->left;
            root->left = nullptr;
            rightMost->right = tmp;
        }

        flatten(root->right);
    }

    // void flatten(TreeNode* root) {
    //     TreeNode *curr = root;
    //     while(curr){
    //         if(curr->left){
    //             TreeNode *rightMost = curr->left;
    //             TreeNode *tmp = rightMost;
    //             while(rightMost->right){
    //                 rightMost = rightMost->right;
    //             }
    //             rightMost->right = curr->right;
    //             curr->right = tmp;
    //             curr->left = nullptr;
    //         }
    //         curr = curr->right;
    //     }
    // }
};
