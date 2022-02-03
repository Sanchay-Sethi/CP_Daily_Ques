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
    void findAns(TreeNode* root, int &sum, int &maxSum){
        if(root==NULL) return;
        sum+=root->val;
        if(root!=NULL and root->left==NULL and root->right==NULL){
            maxSum = max(maxSum, sum);
            return;
        }
        else{
            findAns(root->left, sum, maxSum);
            findAns(root->right, sum, maxSum);
        }
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; 
        int sum = 0;
        findAns(root, sum, maxSum);
        return maxSum;
    }
};
