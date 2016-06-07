class Solution 
{
public:
    int searchInsert( vector<int>& nums, int target ) 
    {
        const size_t size = nums.size();
        int left = 0;
        int right = size;
        while ( left < right - 1 )
        {
            int mid = left + ( right - left ) / 2;
            if ( nums[mid] == target ) return mid;
            if ( nums[mid] < target ) left = mid;
            if ( nums[mid] > target ) right = mid;
        }
        if ( target <= nums[left] ) return left;
        return right;
    }
};
