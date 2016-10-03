// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        // grid[n][m]
        size_t n = grid.size(); // rows
        if(n == 0) return 0;
        size_t m = grid[0].size(); // columns
        if(m == 0) return 0;

        std::vector<int> sums(n * m);

        // top-right corner element
        sums[0] = grid[0][0];

        // the first row
        for(size_t i = 1; i < m; ++i)
        {
            sums[i] = grid[0][i] + sums[i - 1];
        }

        // the first column
        for(size_t i = 1; i < n; ++i)
        {
            sums[i * m] = grid[i][0] + sums[(i - 1) * m];
        }

        // the rest cells
        for(size_t i = 1; i < n; ++i)
        {
            for(size_t j = 1; j < m; ++j)
            {
                sums[i * m + j] = std::min(sums[i * m + j - 1], sums[(i - 1) * m + j]) + grid[i][j];
            }
        }

        return sums[n * m - 1];
    }
};
