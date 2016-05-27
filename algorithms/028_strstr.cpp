class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        const size_t haystackLen = haystack.length();
        const size_t needleLen = needle.length();
        
        if(needleLen == 0) return 0;
        if(needleLen > haystackLen) return -1;
        
        for(size_t i = 0; i <= haystackLen - needleLen; ++i)
        {
             if(haystack.substr(i, needleLen) == needle) return i;
        }
        return -1;
    }
};
