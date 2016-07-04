// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.
// For the purpose of this problem, we define empty string as valid palindrome.
class Solution 
{
private:
    inline bool isDigit(const char c)
    {
        return (47 < c && c < 58);
    }
    inline bool isUpperCaseLetter(const char c)
    {
        return (64 < c && c < 91);
    }
    inline bool isLowerCaseLetter(const char c)
    {
        return (96 < c && c < 123);
    }
    inline bool isLetter(const char c)
    {
        return ( isUpperCaseLetter(c) || isLowerCaseLetter(c) );
    }
    inline bool isAlphaNum(const char c)
    {
        return ( isDigit(c) || isLetter(c) );
    }
    inline char CharToLowerCase(const char c)
    {
        if( isUpperCaseLetter(c) ) return ( c + 32 );
        return c;
    }
    inline bool areEqual(const char lhs, const char rhs)
    {
        if( isLetter(lhs) ) return ( CharToLowerCase(lhs) == CharToLowerCase(rhs) );
        return ( lhs == rhs );
    }
public:
    bool isPalindrome(string s) 
    {
        int left = 0;
        int right = s.length() - 1;
        while(left < right)
        {
            while(!isAlphaNum(s[left]) && left < right) ++left;
            while(!isAlphaNum(s[right]) && left < right) --right;
            if(!areEqual(s[left], s[right])) return false;
            ++left;
            --right;
        }
        return true;
    }
};
