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
    void levelOrderR(vector<vector<int>>& vec, TreeNode* root, size_t level = 0)
    {
        if(root == NULL) return;
        if(vec.size() == level)
        {
            vec.push_back(vector<int>());
        }
        vec[level].push_back(root->val);
        levelOrderR(vec, root->left, level + 1);
        levelOrderR(vec, root->right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        levelOrderR(result, root);
        return result;
    }
};
