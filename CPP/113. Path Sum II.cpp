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
private:

    void dfs(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &ans)
    {   // Concise version:        
        if(!root)   return; 

        path.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum)
            ans.push_back(path);
        else    {
            dfs(root->left, targetSum - root->val, path, ans);
            dfs(root->right, targetSum - root->val, path, ans);
        }
        path.pop_back();
    }    

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;        
        dfs(root, targetSum, path, ans);        // hasPathSum(root, targetSum, path, ans);
        return ans;
    }
};
