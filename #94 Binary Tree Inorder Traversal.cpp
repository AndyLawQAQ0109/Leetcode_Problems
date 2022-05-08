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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};

        int val = root->val;
        if(root->left == nullptr && root->right == nullptr)
            return {val};
        
        vector<int> result;
        vector<int> leftRes = inorderTraversal(root->left);
        leftRes.push_back(val);
        vector<int> rightRes = inorderTraversal(root->right);

        result = leftRes;
        result.insert(result.end(), rightRes.begin(), rightRes.end());
        return result;
    }
};
