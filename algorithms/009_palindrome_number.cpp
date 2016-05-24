class Solution 
{
public:
    bool isPalindrome( int x ) 
    {
        if( x < 0 ) return false;
        
        int p = 1;
        while( x / p > 9 ) p = p * 10;
        
        while( p > 0 )
        {
            if( x / p != x % 10 ) return false;
            x = ( x % p ) / 10;
            p = p / 100;
        }
        return true;
    }
};
