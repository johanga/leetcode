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
    
    TreeNode* buildTreeR(const vector<int>& inorder, const vector<int>& postorder,
                         const size_t inFirstIndex, const size_t inLastIndex, 
                         const size_t postFirstIndex, const size_t postLastIndex)
    {
        // The last element from postorder array should split inorder array into two parts. 
        // The left part is for the left node and the right part is for the right node.
        // The last element from postorder array is for the root node.
        
        if(inFirstIndex >= inLastIndex) return NULL;
        
        const size_t inRootIndex = findIndex(inorder, inFirstIndex, inLastIndex, postorder[postLastIndex - 1]);
        if(inRootIndex == inLastIndex) return NULL;
        
        const size_t leftSize = inRootIndex - inFirstIndex;
        const size_t rightSize = inLastIndex - inRootIndex - 1;
        
        const size_t inLeftFirstIndex = inFirstIndex;
        const size_t inLeftLastIndex = inRootIndex;
        const size_t postLeftFirstIndex = postFirstIndex;
        const size_t postLeftLastIndex = postFirstIndex + leftSize;
        
        const size_t inRightFirstIndex = inRootIndex + 1;
        const size_t inRightLastIndex = inLastIndex;
        const size_t postRightFirstIndex = postLeftLastIndex;
        const size_t postRightLastIndex = postRightFirstIndex + rightSize;
        
        TreeNode* root = new TreeNode(postorder[postLastIndex - 1]);
        root->left = buildTreeR(inorder, postorder, inLeftFirstIndex, inLeftLastIndex, postLeftFirstIndex, postLeftLastIndex);
        root->right = buildTreeR(inorder, postorder, inRightFirstIndex, inRightLastIndex, postRightFirstIndex, postRightLastIndex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        const size_t size = inorder.size();
        return buildTreeR(inorder, postorder, 0, size, 0, size);
    }
};
