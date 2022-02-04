/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
    map<TreeNode*, bool> vis;
    void dfs(TreeNode* target, int cur, int k){
        if(cur==k) ans.push_back(target->val);
        vis[target] = true;
        if(cur<k){
            if(target->left and !vis[target->left]){
                dfs(target->left, cur+1, k);
            }
            if(target->right and !vis[target->right]){
                dfs(target->right, cur+1, k);
            }
            if(parent[target]!=NULL and !vis[parent[target]]){
                dfs(parent[target], cur+1, k);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x->left){
                q.push(x->left);
                parent[x->left] = x;
            }
            if(x->right){
                q.push(x->right);
                parent[x->right] = x;
            }
        }
        
        dfs(target, 0, k);
        return ans;
    }
};
