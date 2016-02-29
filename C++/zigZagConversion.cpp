/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        string retStr;
        int groupSize = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            int j = i, step = i * 2;
            while (j < s.length()) {
                retStr += s[j];
                if (i == 0 || i == numRows - 1)
                    step = groupSize;
                else
                    step = groupSize - step;
                j += step;
            }
        }
    
        return retStr;
    }
};
