/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q;     // {node, vline}
        vector<int> ans;
        map<int, int> mp;              // {vline, data}
        q.push({root, 0});
        
        while(!q.empty())   {
            auto& [node, line] = q.front();
            q.pop();
            
            if(mp.find(line) == mp.end())   
                mp[line] = node->data;
            
            if(node->left)    q.push({node->left, line-1});
            if(node->right)    q.push({node->right, line+1});
        }
        
        for(auto &v: mp)
            ans.push_back(v.second);
            
        return ans;
    }
};
