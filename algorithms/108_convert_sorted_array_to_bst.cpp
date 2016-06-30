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
    TreeNode* sortedArrayToBSTR(const vector<int>& nums, int start, int end)
    {
        const int distance = end - start;
        if(distance == 0) return NULL;
        const int mid = start + distance / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTR(nums, start, mid);
        root->right = sortedArrayToBSTR(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return sortedArrayToBSTR(nums, 0, nums.size()); 
    }
};
