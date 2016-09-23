// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
// 
// Note: m and n will be at most 100.

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        // each cell contains a number of unique paths to reach it
        std::vector<int> vec(m * n);

        // fill the first row by 1
        for(int i = 0; i < m; ++i)
        {
            vec[i] = 1;
        }
        // fill the first column by 1
        for(int i = 1; i < n; ++i)
        {
            vec[i * m] = 1;
        }

        // just summarize left and up values
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                vec[j * m + i] = vec[j * m + i - 1] + vec[(j - 1) * m + i];
            }
        }

        return vec[m * n - 1];
    }
};
