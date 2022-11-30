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
    int length(ListNode *head){
        ListNode *iter = head;
        int res = 0;
        while(iter){
            iter = iter->next;
            res++;
        }
        return res;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return nullptr;
        if(length(head) < k)
            return head;
        
        ListNode *curr = head;
        ListNode *prev = nullptr, *next = nullptr;
        int counter = 0;
        while(counter < k && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            counter++;
        }
        
        if(next)
            head->next = reverseKGroup(next, k);
        
        return prev;
    }
};
