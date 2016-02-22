/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

/*
class Solution {
public:
    int trailingZeroes(int n) {
        int power = int(log10(n) / log10(5));
        int num = 0;
        for(int i = 1; i <= power; ++i){
            num += n / pow(5, i);
        }
        return num;
    }
};
*/
