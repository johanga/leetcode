class Solution
{
public:
    int lengthOfLongestSubstring( string s ) 
    {
        const size_t len = s.length();
        if ( len < 2 ) return len;

        const unsigned short symbolsCount = 256;
        int found[symbolsCount];
        for ( size_t i = 0; i < symbolsCount; ++i )
        {
            found[i] = -1;
        }

        int maxCount = 1;
        int start = 0;
        for ( size_t i = 0; i < len; ++i )
        {
            if ( found[ s[i] ] != -1 )
            {
                if ( found[ s[i] ] >= start ) start = found[ s[i] ] + 1;
            }
            found[ s[i] ] = i;
            if ( i - start + 1 > maxCount ) maxCount = i - start + 1;
        }
        return maxCount;
    }
};
