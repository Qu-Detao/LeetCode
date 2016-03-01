/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] 
is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count 
as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int left = 1, right = 1;
        for (int i = 1; i < nums.size(); i++) {
            left *= nums[i - 1];
            ret[i] *= left;
            right *= nums[nums.size() - i];
            ret[nums.size() - i - 1] *= right;
        }
    
        return ret;
    }
};


/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int numZero = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i])
                product *= nums[i];
            else
                ++numZero;
        }
    
        vector<int> ret(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (numZero == 0)
                ret[i] = product / nums[i];
            else if (nums[i])
                ret[i] = 0;
            else if (numZero == 1)
                ret[i] = product;
            else
                ret[i] = 0;
        }
        
        return ret;
    }
};
*/
