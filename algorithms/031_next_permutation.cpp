// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 > 1,3,2
// 3,2,1 > 1,2,3
// 1,1,5 > 1,5,1

class Solution 
{
public:
    void nextPermutation( vector<int>& nums ) 
    {
        const int size = nums.size();
        if ( size < 2 ) return; // do nothing

        int left = size;
        while ( --left > 0 ) 
        {
            if ( nums[ left ] > nums[ left - 1 ] ) 
            {
                int right = size;
                while ( nums[ --right ] <= nums[ left - 1 ] );
                swap( nums[ right ], nums[ left - 1 ] );
                break;
            }
        }
        reverse( nums.begin() + left, nums.end() );
        
        // STL solution
        // next_permutation( nums.begin(), nums.end() );
    }
};