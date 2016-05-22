class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // easiest way to solve the problem(O(n^2))
        vector<int> res;
        const size_t len = nums.size();
        for(size_t i = 0; i < len; ++i)
        {
            for(size_t j = i + 1; j < len; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};