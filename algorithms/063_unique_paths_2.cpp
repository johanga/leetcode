// Follow up for "Unique Paths":
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

class Solution 
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) 
    {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();
        if(m == 0) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[n - 1][m - 1] == 1) return 0;

        // each cell contains a number of unique paths to reach it
        std::vector<int> vec(m * n);

        // fill the first row
        int val = 1;
        for(int i = 0; i < m; ++i)
        {
            if(obstacleGrid[0][i] == 1) val = 0;
            vec[i] = val;
        }

        // fill the first column
        val = 1;
        for(int i = 1; i < n; ++i)
        {
            if(obstacleGrid[i][0] == 1) val = 0;
            vec[i * m] = val;
        }

        // just summarize left and up values
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[j][i] == 1)
                {
                    vec[j * m + i] = 0;
                }
                else
                {
                    vec[j * m + i] = vec[j * m + i - 1] + vec[(j - 1) * m + i];
                }
            }
        }

        return vec[m * n - 1];
    }
};
