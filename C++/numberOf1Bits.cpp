/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int temp;
        for(int i = 0; i < 32; ++i)
        {
            temp = n & (1 << i);
            if(temp > 0)
                count++;
        }
        return count;
    }
};


/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count;
        for(count = 0; n; ++count)
            n &= n - 1;
        return count;
    }
};
*/