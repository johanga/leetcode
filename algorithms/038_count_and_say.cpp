class Solution 
{
public:
    string countAndSay( int n )
    {
        string seq = "1";
        for ( int i = 0; i < n - 1; ++i )
        {
            stringstream ss;
            const size_t seqLength = seq.length();
            for(size_t j = 0; j < seqLength; ++j)
            {
                char digit = seq[j];
                size_t counter = 1;
                while( seq[ j + counter ] == digit ) ++counter;
                j = j + counter - 1;
                ss << counter << digit;
            }
            seq = ss.str();
        }
        return seq;
    }
};
