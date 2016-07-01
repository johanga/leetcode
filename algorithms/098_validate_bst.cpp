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
    bool isValidBSTR(TreeNode* root, long minValue, long maxValue)
    {
        if(root == NULL) return true;
        if(root->val >= maxValue || root->val <= minValue) return false;
        return (isValidBSTR(root->left, minValue, root->val) && isValidBSTR(root->right, root->val, maxValue));
    }
    
public:
    bool isValidBST(TreeNode* root) 
    {
        return isValidBSTR(root, LONG_MIN, LONG_MAX);
    }
    
};
