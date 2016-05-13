/*
Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,
* Given numerator = 1, denominator = 2, return "0.5".
* Given numerator = 2, denominator = 1, return "2".
* Given numerator = 2, denominator = 3, return "0.(6)".

Hint:
1. No scary math, just apply elementary math knowledge. 
   Still remember how to perform a long division?
2. Try a long division on 4/9, the repeating part is obvious. 
   Now try 4/333. Do you see a pattern?
3. Be wary of edge cases! List out as many test cases as you 
   can think of and test your code thoroughly.
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)  return "0";
        string ret;
        if (numerator < 0 ^ denominator < 0)
            ret += '-';
        long long num = numerator > 0 ? (long long)numerator : (long long)numerator * (-1);
        long long den = denominator > 0 ? (long long)denominator : (long long)denominator * (-1);
        ret += to_string(num / den);
        long long rmd = num % den;
        if (rmd == 0)   return ret;
    
        ret += '.';
        unordered_map<int, int> map;
        while(rmd) {
            if (map.find(rmd) != map.end()) {
                ret.insert(map[rmd], 1, '(');
                ret += ')';
                break;
            }
            map[rmd] = ret.size();
            ret += to_string(rmd * 10 / den);
            rmd = rmd * 10 % den;
        }

        return ret;
    }
};
