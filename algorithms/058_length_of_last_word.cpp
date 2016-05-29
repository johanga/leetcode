class Solution 
{
public:
    int lengthOfLastWord( string s ) 
    {
        size_t counter = 0;
        bool spaceFound = false;
        for ( size_t i = 0; i < s.length(); ++i )
        {
            if ( s[i] == ' ' )
            {
                spaceFound = true;
            }
            else
            {
                if ( spaceFound )
                {
                    spaceFound = false;
                    counter = 0;
                }
                ++counter;
            }
        }
        return counter;
    }
};
