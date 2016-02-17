/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t arrSize = nums.size();
        for(auto it = nums.begin(); it != nums.end(); ++it){
            if(*it == 0){
                nums.erase(it);
                --it;
            }
        }
        size_t nonZeroSize = nums.size();
        for(size_t i = nonZeroSize; i < arrSize; ++i)
            nums.push_back(0);
    }
};