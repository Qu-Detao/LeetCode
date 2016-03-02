/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    string intToRoman(int num) {
        string I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        string X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        string C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        string M[] = { "", "M", "MM","MMM" };
    
        string roman = M[num / 1000] + C[(num % 1000) / 100]
            + X[(num % 100) / 10] + I[num % 10];
    
        return roman;
    }
};

/*
class Solution {
public:
    string intToRoman(int num)
    {
        string roman;

        for(;num / 1000;) { roman += "M";  num -= 1000; }
        if (num >= 900)   { roman += "CM"; num -= 900; }
        if (num >= 500)   { roman += "D";  num -= 500; }
        if (num >= 400)   { roman += "CD"; num -= 400; }

        for(;num / 100;)  { roman += "C";  num -= 100; }
        if (num >= 90)    { roman += "XC"; num -= 90; }
        if (num >= 50)    { roman += "L";  num -= 50; }
        if (num >= 40)    { roman += "XL"; num -= 40; }

        for(;num / 10;)   { roman += "X";  num -= 10; }
        if (num == 9)     { roman += "IX"; return roman; }
        if (num >= 5)     { roman += "V";  num -= 5; }
        if (num == 4)     { roman += "IV"; return roman; }

        for(;num / 1;)    { roman += "I";  num -= 1; }

        return roman;
    }
};
*/
