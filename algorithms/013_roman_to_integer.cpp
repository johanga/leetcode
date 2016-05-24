class Solution 
{
public:
    int romanToInt( string s ) 
    {
        const size_t len = s.length();
        unsigned short number = 0;
        char prev = 0; // previous roman digit
        for( size_t i = 0; i <= len; ++i )
        {
            if( prev )
            {
                switch( i == len ? 0 : s[i] )
                {
                    case 'V':
                    case 'X':
                    {
                        if( prev == 'I' )
                        {
                            number = number - romanDigitToInt(prev);
                        }
                        else
                        {
                            number = number + romanDigitToInt(prev);
                        }
                        break;
                    }
                    case 'L':
                    case 'C':
                    {
                        if( prev == 'X' )
                        {
                            number = number - romanDigitToInt(prev);
                        }
                        else
                        {
                            number = number + romanDigitToInt(prev);
                        }
                        break;
                    }
                    case 'D':
                    case 'M':
                    {
                        if( prev == 'C' )
                        {
                            number = number - romanDigitToInt(prev);
                        }
                        else
                        {
                            number = number + romanDigitToInt(prev);
                        }
                        break;
                    }
                    case 'I':
                    default:
                    {
                        number = number + romanDigitToInt(prev);
                        break;
                    }
               }
          }
          prev = s[i];
     }
     return number;
    }
    
private:
    static unsigned short romanDigitToInt( char c )
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};
