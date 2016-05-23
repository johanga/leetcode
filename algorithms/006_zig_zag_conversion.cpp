class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if( numRows == 1 || numRows >= s.length() ) return s;

        const size_t len = s.length();
        const int step = 2 * numRows - 2;
        const int numZagRows = numRows - 2;

        string res( len, 0 );
        int resi = 0;
        for( int rowi = 0; rowi < numRows; ++rowi )
        {
            int zigi = rowi;
            while( zigi < len )
            {
                res[ resi ] = s[ zigi ];
                ++resi;
                zigi += step;
                if( numZagRows && rowi > 0 && rowi < numRows - 1 )
                {
                    int zagi = zigi - 2 * rowi;
                    if( zagi < len )
                    {
                        res[ resi ] = s[ zagi ];
                        ++resi;
                    }
                }
            }
        }
        return res;
    }
};
