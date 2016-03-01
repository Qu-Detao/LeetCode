/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements 
appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
1. The order of the result is not important. So in the above example, [5, 3] is also correct.
2. Your algorithm should run in linear runtime complexity. Could you implement it using only 
constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorb = 0;
        for(int num : nums)
            aXorb ^= num;
        int lastbit = aXorb & (-aXorb);
        
        vector<int> ab(2, 0);
        for(int num : nums){
            if(lastbit & num)
                ab[0] ^= num;
        }
        ab[1] = aXorb ^ ab[0];
        return ab;
    }
};
