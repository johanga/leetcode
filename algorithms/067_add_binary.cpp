class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        int ita = a.length() - 1;
        int itb = b.length() - 1;
        int carry = 0;
        string result;
        while ( true )
        {
            if( ita < 0 && itb < 0 ) break;
            int sum = carry;
            if( ita >= 0 )
            {
                sum += a[ita] - '0';
                --ita;
            }
            if( itb >= 0 )
            {
                sum += b[itb] - '0';
                --itb;
            }
            switch( sum )
            {
                case 0:
                    result.push_back('0');
                    carry = 0;
                    break;
                case 1:
                    result.push_back('1');
                    carry = 0;
                    break;
                case 2:
                    result.push_back('0');
                    carry = 1;
                    break;
                case 3:
                    result.push_back('1');
                    carry = 1;
                    break;
            }
        }
        if(carry) result.push_back('1');
        reverse( result.begin(), result.end() );
        return result;
    }
};
