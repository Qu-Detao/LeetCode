/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], counter = 0;
        for (int n: nums) {
            if (candidate == n) {
                counter++;
            } else if (counter == 0) {
                candidate = n;
                counter = 1;
            } else {
                counter--;
            }
        }
        return candidate;
    }
};
