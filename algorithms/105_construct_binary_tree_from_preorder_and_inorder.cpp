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
    const size_t findIndex(const vector<int>& vec, const size_t first, const size_t last, const int value)
    {
        for(size_t i = first; i < last; ++i)
        {
            if(vec[i] == value) return i;
        }
        return last;
    }
    
    TreeNode* buildTreeR(const vector<int>& preorder, const vector<int>& inorder,
                         const size_t preFirstIndex, const size_t preLastIndex, 
                         const size_t inFirstIndex, const size_t inLastIndex)
    {
        // The first element from preorder array should split inorder array into two parts. 
        // The left part is for the left node and the right part is for the right node.
        // The first element from preorder array is for the root node.
        
        if(preFirstIndex >= preLastIndex) return NULL;
        
        const size_t inRootIndex = findIndex(inorder, inFirstIndex, inLastIndex, preorder[preFirstIndex]);
        if(inRootIndex == inLastIndex) return NULL;
        
        const size_t leftSize = inRootIndex - inFirstIndex;
        const size_t rightSize = inLastIndex - inRootIndex - 1;
        
        const size_t preLeftFirstIndex = preFirstIndex + 1;
        const size_t preLeftLastIndex = preLeftFirstIndex + leftSize;
        const size_t inLeftFirstIndex = inFirstIndex;
        const size_t inLeftLastIndex = inRootIndex;
        
        const size_t preRightFirstIndex = preLeftLastIndex;
        const size_t preRightLastIndex = preRightFirstIndex + rightSize;
        const size_t inRightFirstIndex = inRootIndex + 1;
        const size_t inRightLastIndex = inLastIndex;        
        
        TreeNode* root = new TreeNode(preorder[preFirstIndex]);
        root->left = buildTreeR(preorder, inorder, preLeftFirstIndex, preLeftLastIndex, inLeftFirstIndex, inLeftLastIndex);
        root->right = buildTreeR(preorder, inorder, preRightFirstIndex, preRightLastIndex, inRightFirstIndex, inRightLastIndex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        const size_t size = preorder.size();
        return buildTreeR(preorder, inorder, 0, size, 0, size);
    }
};
