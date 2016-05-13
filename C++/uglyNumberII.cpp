/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:
1. The naive approach is to call isUgly for every number until you reach the nth one. 
   Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
2. An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
3. The key is how to maintain the order of the ugly numbers. Try a similar approach 
   of merging from three sorted lists: L1, L2, and L3.
4. Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, 0);
        nums[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for(int i = 1; i < n; ++i){
            nums[i] = min(min(nums[index2] * 2, nums[index3] * 3), nums[index5] * 5);
            if(nums[index2] * 2 == nums[i]) index2++;
            if(nums[index3] * 3 == nums[i]) index3++;
            if(nums[index5] * 5 == nums[i]) index5++;
        }
        return nums[n - 1];
    }
};
