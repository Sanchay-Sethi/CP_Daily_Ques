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
    int findGoodNodes(TreeNode* root, int maxSoFar){
        if(root==NULL) return 0;
        int count;
        if(root->val>=maxSoFar)
            count=1;
        else count = 0;
        maxSoFar = max(maxSoFar, root->val);
        count += findGoodNodes(root->left, maxSoFar);
        count += findGoodNodes(root->right, maxSoFar);
        return count;
    }
    int goodNodes(TreeNode* root) {
        int ans = findGoodNodes(root, INT_MIN);
        return ans;
    }
};
