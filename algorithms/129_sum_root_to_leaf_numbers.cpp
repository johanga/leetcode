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
    void sumNumbersR(int& res, TreeNode* root, int parent)
    {
        if(root==NULL) return;
        const int value = parent * 10 + root->val;
        if(root->left == NULL && root->right == NULL) // is leaf
        {
            res += value;
            return;
        }
        sumNumbersR(res, root->left, value);
        sumNumbersR(res, root->right, value);
    }
public:
    int sumNumbers(TreeNode* root) 
    {
        int result = 0;
        sumNumbersR(result, root, 0);
        return result;
    }
};
