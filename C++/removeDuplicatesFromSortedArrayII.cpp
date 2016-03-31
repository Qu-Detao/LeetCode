/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums 
being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int count = 0;
        int curNum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int j = i;
            while (i < nums.size() && nums[i] == curNum)
                ++i;
            if (i - j > 1)
                count += i - j - 1;
            curNum = i < nums.size() ? nums[i] : nums[i - 1];
            nums[i - count - 1] = nums[i - 1];
            nums[i - count] = curNum;
        }
        return nums.size() - count;
    }
};
