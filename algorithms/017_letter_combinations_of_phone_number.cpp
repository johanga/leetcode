class Solution 
{
private:
    static string getDigitLetters( char d )
    {
        switch ( d )
        {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: break;
        }
        return "";
    }

    static void addDigit( vector< string >& result, const string& digitLetters )
    {
        const size_t resultSize = result.size();
        const size_t lettersSize = digitLetters.length();
        if ( resultSize == 0 )
        {
            for ( size_t i = 0; i < lettersSize; ++i )
            {
                result.push_back( string( 1, digitLetters[i] ) );
            }
        }
        else
        {
            for ( size_t i = 0; i < resultSize; ++i )
            {
                for ( size_t j = 1; j < lettersSize; ++j )
                {
                    result.push_back( result[i] + string( 1, digitLetters[j] ) );
                }
                result[i].push_back( digitLetters[0] );
            }
        }
    }

public:
    vector< string > letterCombinations( string digits )
    {
        const size_t size = digits.size();
        vector< string > result;
        for ( size_t i  = 0; i < size; ++i )
        {
            addDigit( result, getDigitLetters( digits[i] ) );
        }
        return result;
    }
};
