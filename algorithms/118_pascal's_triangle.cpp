// Given numRows, generate the first numRows of Pascal's triangle.
// For example, given numRows = 5,
// Return
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        if(numRows == 0) return result;

        vector<int> first;
        first.push_back(1);
        result.push_back(first);
        if(numRows == 1) return result;

        for(size_t i = 1; i < numRows; ++i)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(size_t j = 1; j < result[i-1].size(); ++j)
            {
                tmp.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }

        return result;
    }
};
