/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        root->next = NULL;
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                if(curr->right)
                    curr->left->next = curr->right;
                else if(!curr->next)
                    curr->left->next = NULL;
                else{
                    Node *tmp = curr;
                    while(tmp->next){
                        if(tmp->next->left){
                            curr->left->next = tmp->next->left;
                            break;
                        }
                        else if(tmp->next->right){
                            curr->left->next = tmp->next->right;
                            break;
                        }
                        else
                            tmp = tmp->next;
                    }
                    if(!tmp->next)
                        curr->left->next = NULL;
                }
            }
            if(curr->right){
                q.push(curr->right);
                if(!curr->next)
                    curr->right->next = NULL;
                else{
                    Node *tmp = curr;
                    while(tmp->next){
                        if(tmp->next->left){
                            curr->right->next = tmp->next->left;
                            break;
                        }
                        else if(tmp->next->right){
                            curr->right->next = tmp->next->right;
                            break;
                        }
                        else
                            tmp = tmp->next;
                    }
                    if(!tmp->next)
                        curr->right->next = NULL;
                }
            }
        }
        return root;
    }
};
