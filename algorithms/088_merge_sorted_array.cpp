// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
// The number of elements initialized in nums1 and nums2 are m and n respectively.

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        nums1.resize(m);
        nums2.resize(n);
        
        size_t i1 = 0;
        size_t i2 = 0;
        while ( i1 < m + n && i2 < n )
        {
            if ( nums2[i2] < nums1[i1] )
            {
                nums1.insert( nums1.begin() + i1, nums2[i2] );
                ++i2;
            }
            ++i1;
        }
        if ( i2 < n )
        {
            nums1.insert( nums1.end(), nums2.begin() + i2, nums2.end() );
        }
    }
};
