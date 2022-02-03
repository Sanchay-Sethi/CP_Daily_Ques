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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flip = false;
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            flip = !flip;
            for(int i = 0; i<n; i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left){
                   q.push(x->left); 
                }
                if(x->right){
                    q.push(x->right);
                }
                temp.push_back(x->val);
            }
            if(!flip) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
