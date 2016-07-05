// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.
// For example, given array S = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        const int size = nums.size();
        if(size < 3) return result;
        int i = 0;
        while(i < size)
        {
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            
            int left = i + 1;
            int right = size - 1;
            while(left < right)
            {
                const int twoSum = nums[left] + nums[right];
                if(twoSum < -nums[i])
                {
                    while(nums[left] == nums[++left]); // shift left and avoid duplicates
                }
                else if(twoSum > -nums[i])
                {
                    while(nums[right] == nums[--right]); // shift right and avoid duplicates
                }
                else
                {
                    result.push_back(vector<int>({nums[i], nums[left], nums[right]}));
                    // shift both and avoid duplicates
                    while(nums[left] == nums[++left]);
                    while(nums[right] == nums[--right]);
                }
            }

            while(nums[i] == nums[++i]); // shift first and avoid duplicates
        }
        return result;
    }
};
