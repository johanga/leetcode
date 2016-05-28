class Solution
{
private:
    static string div1000( int num )
    {
        string roman;
        const int thousands = num / 1000;
        switch ( thousands )
        {
            case 1: roman = "M"; break;
            case 2: roman = "MM"; break;
            case 3: roman = "MMM"; break;
            default: break;
        }
        div900( num % 1000, roman );
        return roman;
    }

    static void div900( int num, std::string& roman )
    {
        if ( num / 900 == 1 )
        {
            roman += "CM";
            div90( num % 900, roman );
        }
        else
        {
            div500( num, roman );
        }
    }

    static void div500( int num, std::string& roman )
    {
        if( num / 500 == 1 )
        {
            roman += "D";
            div100( num % 500, roman );
        }
        else
        {
            div400( num, roman );
        }
    }

    static void div400( int num, std::string& roman )
    {
        if ( num / 400 == 1 )
        {
            roman += "CD";
            div90( num % 400, roman );
        }
        else
        {
            div100( num, roman );
        }
    }

    static void div100( int num, std::string& roman )
    {
        const int hundreds = num / 100;
        switch ( hundreds )
        {
            case 1: roman += "C"; break;
            case 2: roman += "CC"; break;
            case 3: roman += "CCC"; break;
            default: break;
        }
        div90( num % 100, roman );
    }

    static void div90( int num, std::string& roman )
    {
        if ( num / 90 == 1 )
        {
            roman += "XC";
            div9( num % 90, roman );
        }
        else
        {
            div50( num, roman );
        }
    }

    static void div50( int num, std::string& roman )
    {
        if( num / 50 == 1 )
        {
            roman += "L";
            div10( num % 50, roman );
        }
        else
        {
            div40( num, roman );
        }
    }

    static void div40( int num, std::string& roman )
    {
        if ( num / 40 == 1 )
        {
            roman += "XL";
            div9( num % 40, roman );
        }
        else
        {
            div10( num, roman );
        }
    }

    static void div10( int num, std::string& roman )
    {
        const int tens = num / 10;
        switch ( tens )
        {
            case 1: roman += "X"; break;
            case 2: roman += "XX"; break;
            case 3: roman += "XXX"; break;
            default: break;
        }
        div9( num % 10, roman );
    }

    static void div9( int num, std::string& roman )
    {
        if ( num / 9 == 1 )
        {
            roman += "IX";
        }
        else
        {
            div5( num, roman );
        }
    }

    static void div5( int num, std::string& roman )
    {
        if ( num / 5 == 1 )
        {
            roman += "V";
            div1( num % 5, roman );
        }
        else
        {
            div4( num, roman );
        }
    }

    static void div4( int num, std::string& roman )
    {
        if( num == 4 )
        {
            roman += "IV";
        }
        else
        {
            div1( num, roman );
        }
    }

    static void div1( int num, std::string& roman )
    {
        switch ( num )
        {
            case 1: roman += "I"; break;
            case 2: roman += "II"; break;
            case 3: roman += "III"; break;
            default: break;
        }
    }

public:
    // I 1
    // V 5
    // X 10
    // L 50
    // C 100
    // D 500
    // M 1000
    string intToRoman( int num )
    {
        if ( num < 1 || num > 3999 ) return "FAILED";
        return div1000(num);
    }
};
