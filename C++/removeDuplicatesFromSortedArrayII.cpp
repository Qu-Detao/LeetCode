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
        int j = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(j < 2 || nums[i] > nums[j - 2])
                nums[j++] = nums[i];
        }
        return j;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i = 2; i < n; ++i){
            if(nums[i] == nums[i - 2 - count])
                count++;
            else
                nums[i - count] = nums[i];
        }
        return n - count;
    }
};
