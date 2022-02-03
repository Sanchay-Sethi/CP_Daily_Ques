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
    int diameter(TreeNode* root, int &res){
        if(root == NULL) return 0;
        int l = diameter(root->left, res);
        int r = diameter(root->right, res);
        
        int temp = max(l, r) + 1;
        int ans = max(temp, l + r + 1);
        res = max(res, ans);
        
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        diameter(root, res);
        return res-1;
    }
};
