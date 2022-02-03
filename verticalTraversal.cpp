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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //Using BFS
        map<int, map<int, multiset<int>>> mp; // vertical level, Horizontal level, values
        queue<pair<TreeNode *, pair<int, int>>> q; // Value, vertical level, Horizontal level
        q.push({root, {0, 0}}); // Node, VL : 0, HL : 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            TreeNode * temp = x.first;
            int vert_level = x.second.first;
            int hori_level = x.second.second;
            mp[vert_level][hori_level].insert(temp->val);
            if(temp->left){
                q.push({temp->left, {vert_level - 1, hori_level + 1}});
            }
            if(temp->right){
                q.push({temp->right, {vert_level + 1, hori_level + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto x : mp){
            vector<int> temp;
            for(auto y : x.second){
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
