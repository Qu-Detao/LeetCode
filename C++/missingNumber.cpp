/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        int num = (nums.size() + 1) * nums.size() / 2 - sum;
        return num;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            num ^= nums[i];
            num ^= i;
        }
        return num;
    }
};
