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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;

        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty())   {
            int maxi = INT_MIN;
            int size = Q.size();
            for(int i=0; i<size; i++)   {
                TreeNode* node = Q.front();
                Q.pop();
                maxi = max(maxi, node->val);

                if(node->left)  Q.push(node->left);
                if(node->right)  Q.push(node->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
