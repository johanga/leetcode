class Solution 
{
public:
    string longestPalindrome( string s ) 
    {
        // Manacher's algorithm.
        const char delimeter = '#';
        const size_t len = s.length();
        const size_t tmplen = 2 * len + 1;

        // create auxiliary string
        string tmpstr( tmplen, 0 );
        for ( size_t i = 0; i < len; ++i )
        {   
            tmpstr[ 2 * i ] = delimeter;
            tmpstr[ 2 * i + 1 ] = s[ i ];
        }
        tmpstr[ 2 * len ] = delimeter;

        // find maximum palindrome
        size_t maxPalindromeIndex = 0;
        size_t maxPalindromeCount = 0;
        for ( size_t i = 0; i < tmplen; ++i )
        {
            size_t maxCount = min( i, tmplen - 1 - i );
            size_t counter = 1;
            while ( tmpstr[ i - counter ] == tmpstr[ i + counter ] && counter <= maxCount ) ++counter;
            if ( counter > maxPalindromeCount )
            {
                maxPalindromeIndex = i;
                maxPalindromeCount = counter;
            }
        }

        string palindrome = tmpstr.substr( maxPalindromeIndex - maxPalindromeCount + 1, 2 * maxPalindromeCount - 1 );
        palindrome.erase( remove( palindrome.begin(), palindrome.end(), delimeter ), palindrome.end() ) ; 
        return palindrome;
    }
};
