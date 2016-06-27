/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    void zigzagOrderR(vector<vector<int>>& vec, TreeNode* root, size_t level = 0)
    {
        if(root == NULL) return;
        if(vec.size() == level)
        {
            vec.push_back(vector<int>());
        }
        vec[level].push_back(root->val);
        zigzagOrderR(vec, root->left, level + 1);
        zigzagOrderR(vec, root->right, level + 1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        zigzagOrderR(result, root);
        for(size_t i = 1; i < result.size(); i = i + 2)
        {
            reverse(result[i].begin(), result[i].end());
        }
        return result;        
    }
};
