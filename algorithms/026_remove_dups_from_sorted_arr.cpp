class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        vector<int>::iterator last = unique(nums.begin(), nums.end());
        
        // without erasing
        return distance(nums.begin(), last);
        
        // with erasing
        //nums.erase(last, nums.end());
        //return nums.size();
    }
};
