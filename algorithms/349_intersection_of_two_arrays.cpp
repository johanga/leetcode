class Solution 
{
public:
    vector<int> intersection( vector<int>& nums1, vector<int>& nums2 ) 
    {
        vector<int> result;
        if( nums1.empty() || nums2.empty() ) return result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        size_t i = 0;
        size_t j = 0;
        while ( i < nums1.size() && j < nums2.size() )
        {
            if ( nums1[i] == nums2[j] )
            {
                result.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if (nums1[i] < nums2[j])
            {
                ++i;
            }
            else if (nums1[i] > nums2[j])
            {
                ++j;
            }
        }
        
        vector<int>::iterator last = unique(result.begin(), result.end());
        result.erase(last, result.end());
        return result;
    }
};
