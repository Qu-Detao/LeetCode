/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int num = 0;
        for(int i = 0; i < len; ++i){
            int base = int(s[i]) - int('A') + 1;
            num += base * pow(26, len - 1 - i);
        }
        return num;
    }
};