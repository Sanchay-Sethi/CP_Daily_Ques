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
    void findAns(TreeNode *root, vector<string> &ans, string s){
        if(root==NULL) return;
        ostringstream str;
        str<<root->val;
        string temp = str.str();
        s = s + temp + "->";
        if(root!=NULL and root->left==NULL and root->right==NULL){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
            s = "";
        }
        findAns(root->left, ans, s);
        findAns(root->right, ans, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
        vector<string> ans;
        string s = "";
        findAns(root, ans, s);
        return ans; 
    }
};
