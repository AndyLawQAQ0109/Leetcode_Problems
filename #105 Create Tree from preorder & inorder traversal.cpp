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
    // map each value of inorder vector to its index
    unordered_map<int, int> valToIdx; // vector<int> inorder: nodeVal -> index
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();

        // initialize map
        for(int i=0; i<size; i++)
            valToIdx[inorder[i]] = i;

        return recurr(preorder, inorder, 0, size - 1, 0, size - 1);
    }
    TreeNode* recurr(vector<int> &preorder, vector<int> & inorder, int preLeft, int preRight, int inLeft, int inRight){
        // Test Purpose
        cout<<"Root: "<< preorder[preLeft]<<" -- "<<preLeft<<" "<<preRight<<" "<<inLeft<<" "<<inRight<<endl;
        
        // base case
        if(preLeft > preRight)
            return nullptr;

        // first value in preorder vector is always the root
        // Get root's index in preoder vector
        int preRootIdx = preLeft; 
        int inRootIdx = valToIdx[preorder[preRootIdx]]; // Get root value's index at inorder vector

        int left_inorderNodes = inRootIdx - inLeft; // # of left subtree nodes

        // Create root TreeNode
        TreeNode *root = new TreeNode(preorder[preRootIdx]);
        // Leftsubtree in preoder & inorder vectors' index ranges
        root->left = recurr(preorder, inorder, preLeft + 1, preLeft + left_inorderNodes, inLeft, inRootIdx - 1);
        // Rightsubtree in preoder & inorder vectors' index ranges
        root->right = recurr(preorder, inorder, preLeft + left_inorderNodes + 1, preRight, inRootIdx + 1, inRight);
        return root;
    }
};
