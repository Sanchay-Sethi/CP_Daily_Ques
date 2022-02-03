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
    int findIndex(vector<int> inorder, int start, int end, int val){
        for(int i = start; i<=end; i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int start, int end, int &cur){
        if(start>end) return NULL;
        TreeNode* node = new TreeNode(preorder[cur]);
        cur++;
        if(start==end) return node;
        else{
            int index = findIndex(inorder, start, end, node->val);
            node->left = rec(preorder, inorder, start, index-1, cur);
            node->right = rec(preorder, inorder, index+1, end, cur);
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        int end = inorder.size()-1;
        int cur = 0;
        TreeNode * head = rec(preorder, inorder, start, end, cur);
        return head;
    }
};
