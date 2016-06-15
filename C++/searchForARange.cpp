/*
Given a sorted array of integers, find the starting and ending 
position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        if(nums[lo] != target) return ret;
        else ret[0] = lo;
        
        hi = nums.size() - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2 + 1;
            if(nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid;
        }
        ret[1] = hi;
        
        return ret;
    }
};
