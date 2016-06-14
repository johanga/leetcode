// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution 
{
public:
    // Returns the n-number in Fibonacci sequence
    int climbStairs(int n) 
    {
        if ( n == 0 ) return 1;
        if ( n == 1 ) return 1;
        if ( n == 2 ) return 2;
        
        // ways count for (i-2) step is equal to ways with count for ways with the last double step
        // ways count for (i-1) step is equal to ways count with for ways with the last single step
        
        int current = 0;
        int prev2 = 1; // hard-coded value for n = 1
        int prev1 = 2; // hard-coded value for n = 2
        for ( size_t i = 3; i <= n; ++i )
        {
            current = prev2 + prev1;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
        
        // Recursive solution that is not accepted because of "Time Limit Exceed"
        // return climbStairs( n-1 ) + climbStairs( n-2 );
        
        // Binet's formula
        // return static_cast< int >( ( pow( ( 1.0 + sqrt(5.0) ) / 2.0, n + 1 ) - pow( ( 1.0 - sqrt(5.0) ) / 2.0, n + 1 ) ) / sqrt(5.0) );
    }
};
