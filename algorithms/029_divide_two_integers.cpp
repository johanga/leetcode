// Divide two integers without using multiplication, division and mod operator.
// If it is overflow, return MAX_INT.

class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        bool isNegative = false;
        if(dividend < 0) isNegative = !isNegative;
        if(divisor < 0) isNegative = !isNegative;

        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dividendL = labs(dividend);
        long long divisorL = labs(divisor);

        int result = 0;
        while(dividendL >= divisorL)
        {
            long long tmp = divisorL;
            int mul = 1;
            while(dividendL >= tmp << 1)
            {
                tmp = tmp << 1;
                mul = mul << 1;
            }
            dividendL -= tmp;
            result += mul;
        }

        return isNegative ? -result : result;
    }
};
