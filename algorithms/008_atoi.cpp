class Solution 
{
public:
    int myAtoi( string str ) 
    {
        const size_t len = str.length();

        // find start char
        size_t start = 0;
        while ( str[start] == ' ' )
        {
            ++start;
        }

        // check for negative
        bool negative = false;
        if ( str[start] == '-' )
        {
            negative = true;
            ++start;
        }
        else if ( str[start] == '+' )
        {
            ++start;
        }

        // convert int
        long long num = 0;
        for ( size_t i = start; i < len; ++i )
        {
            // is digit
            if ( str[i] > 47 && str[i] < 58 )
            {
                if ( negative )
                {
                    num = num * 10 - ( str[i] - 48 );
                    // check for min overflow
                    if ( num < INT_MIN )
                    {
                        num = INT_MIN;
                        break;
                    }
                }
                else
                {
                    num = num * 10 + ( str[i] - 48 );
                    // check for max overflow
                    if ( num > INT_MAX )
                    {
                        num = INT_MAX;
                        break;
                    }
                }    
            }
            else
            {
                break;
            }
        }

        return num; 
    }
};