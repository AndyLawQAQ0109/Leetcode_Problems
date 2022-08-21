/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getLength(ListNode* head) {
        int ret = 0;
        for (; head != nullptr; ++ret, head = head->next);
        return ret;
    }

    TreeNode* buildTree(ListNode*& head, int left, int right) {

        if (left > right) {
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        return buildTree(head, 0, length - 1);
    }
    // ListNode *getMiddle(ListNode *l, ListNode *r){
    //     ListNode *f = l, *s = l;
    //     while(f != r && f->next != r){
    //         f = f->next->next;
    //         s = s->next;
    //     }
    //     return s;
    // }
    // TreeNode* sortedListToBST(ListNode* head) {
    //     return build(head, nullptr);
    // }
    // TreeNode* build(ListNode *l, ListNode *r){
    //     if(l == r)
    //         return nullptr;

    //     ListNode *mid = getMiddle(l, r);
    //     TreeNode *root = new TreeNode(mid->val);
    //     root->left = build(l, mid);
    //     root->right = build(mid->next, r);
    //     return root;
    // }
};
