class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        const size_t strsSize = strs.size();
        if (strsSize == 0) return "";
        if (strsSize == 1) return strs[0];
        
        string prefix = longestCommonPrefix(strs[0],strs[1]);
        for(size_t i = 2; i < strsSize; ++i)
        {
            prefix = longestCommonPrefix(prefix, strs[i]);
        }
        return prefix;
    }
    
private:
    string longestCommonPrefix(const string& s1, const string& s2)
    {
        const size_t l1 = s1.length();
        const size_t l2 = s2.length(); 
        const size_t minLength = ( l1 < l2 ? l1 : l2 );
        for(size_t i = 0; i < minLength; ++i)
        {
            if(s1[i]!=s2[i]) return s1.substr(0, i);
        }
        return s1.substr(0, minLength);
    }
};
