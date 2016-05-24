class Solution 
{
public:
    bool isValid(string s) 
    {
        const size_t len = s.length();
        stack<char> st;
        for (size_t i = 0; i < len; ++i)
        {
            switch (s[i])
            {
                case '(':
                case '{':
                case '[':
                    st.push(s[i]); // keep open bracket
                    break;
                case ')':
                case '}':
                case ']':
                    // check for last open bracket
                    if (st.empty() || st.top() != leftByRight(s[i]))
                    {
                        return false; // incorrect close bracket
                    }
                    else
                    {
                        st.pop(); // found appropriate close bracket
                    }
                    break;
                default: // ignore other symbols
                    break;
            }
        }
        if (!st.empty()) return false; // not enough close brackets
        return true;
    }
    
private:
    static char leftByRight(char right)
    {
        switch (right)
        {
            case ')': return '(';
            case '}': return '{';
            case ']': return '[';
            default: break;
        }
        return 0;
    }
};
