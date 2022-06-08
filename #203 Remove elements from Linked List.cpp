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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        while(head != nullptr && head->val == val){
            head = head->next;
        }
        if(head == nullptr) return nullptr;
        
        ListNode *prev = head, *curr = head->next;
        while(curr != nullptr){
            if(curr->val == val){
                curr = curr->next;
                prev->next = curr;               
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
