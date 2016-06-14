// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
// [
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
// ]

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector< string > vec;
        generateParenthesis( n, vec, "", 0 );
        return vec;
    }

private:
    void generateParenthesis( int n, vector< string >& vec, const string& tmp, int open )
    {
        const int len = tmp.length();
        if ( open > len - open )
        {
            generateParenthesis( n, vec, tmp + ")", open );
        }
        if ( open < n )
        {
            generateParenthesis(n, vec, tmp + "(", open + 1 );
        }
        if ( len == n * 2 ) 
        {
            vec.push_back( tmp );
        }
    }
    
};
