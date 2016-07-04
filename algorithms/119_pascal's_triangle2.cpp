// Given an index k, return the kth row of the Pascal's triangle.
// For example, given k = 3,
// Return [1,3,3,1].
// Note:
// Could you optimize your algorithm to use only O(k) extra space?
class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        ++rowIndex;
        
        vector<int> result;
        if(rowIndex == 0) return result;

        vector<int> prev;
        prev.push_back(1);
        if(rowIndex == 1) return prev;

        for(size_t i = 1; i < rowIndex; ++i)
        {
            result.clear();
            result.push_back(1);
            for(size_t j = 1; j < prev.size(); ++j)
            {
                result.push_back(prev[j-1] + prev[j]);
            }
            result.push_back(1);
            prev = result;
        }

        return result;
    }
};
