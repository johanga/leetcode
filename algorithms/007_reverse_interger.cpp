class Solution 
{
public:
    int reverse( int x ) 
    {
        long y = 0;
        while ( x != 0 )
        {
            y = y * 10 + ( x % 10 );
            if( abs(y) > INT_MAX ) return 0; // overflow
            x = x / 10;
        }
        return y;
    }
};
