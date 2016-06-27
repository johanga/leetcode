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
    void rightSideViewR(vector<int>& vec, TreeNode* root, size_t level = 0)
    {
        if(root == NULL) return;
        if(vec.size() == level)
        {
            vec.push_back(root->val);
        }
        rightSideViewR(vec, root->right, level + 1);
        rightSideViewR(vec, root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        rightSideViewR(result, root);
        return result;
    }
};
