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
    int fun(TreeNode* node, int& maxSum)    {
        if(!node)   return 0;

        int lsum = max(0, fun(node->left, maxSum));
        int rsum = max(0, fun(node->right, maxSum));

        maxSum = max(maxSum, node->val + lsum + rsum);

        return (node->val + max(lsum, rsum));
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        fun(root, maxSum);
        return maxSum;
    }
};
