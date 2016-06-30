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
    void binaryTreePathsR(vector<string>& result, TreeNode* root, const string& prev)
    {
        if(root == NULL) return;
        stringstream s;
        if(!prev.empty())
        {
            s << prev << "->";
        }
        s << root->val;
        if(root->left == NULL && root->right == NULL) 
        {
            result.push_back(s.str());
            return;
        }
        binaryTreePathsR(result, root->left, s.str());
        binaryTreePathsR(result, root->right, s.str());
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        binaryTreePathsR(result, root, "");
        return result;
    }
};
