// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
// Note: The solution set must not contain duplicate quadruplets.
// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
        int size = nums.size();
        if(size < 4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size - 3; ++i)
        {
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if(nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < size - 2; ++j)
            {
                if( nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if( nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target ) continue;
                if( j > i + 1 && nums[j] == nums[j-1] ) continue;
                
                int left = j + 1;
                int right = size - 1;
                while(left < right)
                {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if(sum < target)
                    {
                        left++;
                    }
                    else if(sum > target )
                    {
                        right--;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(nums[left] == nums[++left] && left < right);
                        while(nums[right] == nums[--right] && left < right);
                    }
                }
            }
        }
        return result;
    }
};
