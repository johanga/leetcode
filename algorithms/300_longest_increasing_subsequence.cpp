// Given an unsorted array of integers, find the length of longest increasing subsequence.
// 
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
// 
// Your algorithm should run in O(n2) complexity.
// 
// Follow up: Could you improve it to O(n log n) time complexity?

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        std::vector<int> lens(nums.size());
        std::vector<int> prev(nums.size());

        for(size_t i = 0; i < nums.size(); ++i)
        {
            lens[i] = 1;
            prev[i] = i;
            for(size_t j = 0; j < i; ++j)
            {
                // increasing
                if(nums[i] > nums[j] && lens[i] < lens[j] + 1)
                {
                    lens[i] = lens[j] + 1;
                    prev[i] = j;
                }
            }
        }

        const std::vector<int>::const_iterator found = std::max_element(lens.begin(), lens.end());
        return (found == lens.end() ? 0 : *found);
    }
};
