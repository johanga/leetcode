class Solution 
{
public:
    bool isValidSudoku( vector<vector<char>>& board ) 
    {
        const size_t SIZE = 9;
        const size_t BOX_SIZE = SIZE / 3;
        const unsigned short ANSI_DIGIT_INDENT = 48;
        
        const size_t boardSize = board.size();
        if( boardSize != SIZE ) return false;
        if( boardSize == 0 ) return false; 
        if( board[0].size() != SIZE ) return false;
        
        // [digit][row number]
        bool isDigitInRow[SIZE][SIZE] = {0};
        
        // [digit][column number]
        bool isDigitInCol[SIZE][SIZE] = {0};
        
        // [digit][box number]
        // [0][1][2]
        // [3][4][5]
        // [6][7][8]
        bool isDigitInBox[SIZE][SIZE] = {0};
        
        for(size_t i = 0; i < SIZE; ++i) // i - row number
        {
            for(size_t j = 0; j < SIZE; ++j) // j - column number
            {
                const char digit = board[i][j];
                if(digit != '.')
                {
                    // row
                    const unsigned short digitIndex = digit - ANSI_DIGIT_INDENT - 1;
                    if( isDigitInRow[digitIndex][i] )
                    {
                        return false;
                    }
                    else
                    {
                        isDigitInRow[digitIndex][i] = true;
                    }
                    
                    // column
                    if( isDigitInCol[digitIndex][j] )
                    {
                        return false;
                    }
                    else
                    {
                        isDigitInCol[digitIndex][j] = true;
                    }
                    
                    // box
                    const unsigned short boxIndex = ( i / BOX_SIZE ) * BOX_SIZE + j / BOX_SIZE;
                    if( isDigitInBox[digitIndex][boxIndex] )
                    {
                        return false;
                    }
                    else
                    {
                        isDigitInBox[digitIndex][boxIndex] = true;
                    }
                }
            }
        }

        return true;
    }
};
