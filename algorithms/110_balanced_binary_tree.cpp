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
    bool isBalancedR(TreeNode* root, int& len)
    {
        if(root == NULL)
        {
            len = 0;
            return true;
        }
        int leftLen, rightLen;
        bool leftRes, rightRes;
        leftRes = isBalancedR(root->left, leftLen);
        rightRes = isBalancedR(root->right, rightLen);
        if(abs(leftLen - rightLen) > 1) return false;
        len = max(leftLen, rightLen) + 1;
        return leftRes && rightRes;
        
    }
public:
    bool isBalanced(TreeNode* root) 
    {
        int len = 0;
        return isBalancedR(root, len);
    }
};
