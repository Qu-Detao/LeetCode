/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that 
there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        
        vector<int> lengths(nums.size(), 1);
        int maxLength = 1;
        for(int j = 1; j < nums.size(); ++j){
            for(int i = 0; i < j; ++i){
                if(nums[i] < nums[j])
                    lengths[j] = max(lengths[i] + 1, lengths[j]);
            }
            maxLength = max(maxLength, lengths[j]);
        }
        
        return maxLength;
    }
};
