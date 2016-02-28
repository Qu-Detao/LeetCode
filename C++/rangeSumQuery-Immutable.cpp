/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
* You may assume that the array does not change.
* There are many calls to sumRange function.
*/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        sums = sum(nums);
    }

    int sumRange(int i, int j) {
        if (i < 0 || i > j)
            return 0;
        else if (i == 0)
            return sums[j];
        else
            return sums[j] - sums[i - 1];
    }

private:
    vector<int> sums;
    vector<int> sum(vector<int> &nums) {
        vector<int> sumVec;
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            sumVec.push_back(curSum);
        }
        return sumVec;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
