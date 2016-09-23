// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// 
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.
// 
// More practice:
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        const size_t len = nums.size();
        std::vector<int> sums(len);
        std::vector<int> lengths(len);

        sums[len - 1] = nums[len - 1];
        lengths[len - 1] = 1;
        for(int i = len - 2; i >= 0; --i)
        {
            if(nums[i] > nums[i] + sums[i + 1])
            {
                sums[i] = nums[i];
                lengths[i] = 1;
            }
            else
            {
                sums[i] = nums[i] + sums[i + 1];
                lengths[i] = lengths[i + 1] + 1;
            }
        }

        return *std::max_element(sums.begin(), sums.end());
    }
};
