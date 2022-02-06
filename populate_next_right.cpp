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
        Node *levelNode = root;
        while(levelNode != NULL and levelNode->left!=NULL){
            Node* temp = levelNode;
            while(true){
                temp->left->next = temp->right;
                if(temp->next==NULL) break;
                temp->right->next = temp->next->left;
                temp = temp->next;
            }
            levelNode = levelNode->left;
        }
        return root;
    }
};
