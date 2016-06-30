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
    void pathSumHelp(vector<vector<int>>& result, TreeNode* root, int sum, vector<int>& path)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && root->val == sum)
        {
            if(root->val == sum)
            {
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        pathSumHelp(result, root->left, sum - root->val, path);
        pathSumHelp(result, root->right, sum - root->val, path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> result;
        vector<int> path;
        pathSumHelp(result, root, sum, path);
        return result;
    }
};
