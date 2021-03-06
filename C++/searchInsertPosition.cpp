/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0, tail = nums.size();
        while(head < tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] >= target)
                tail = mid;
            else
                head = mid + 1;
        }
        return head;
    }
};

/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0 || nums[0] >= target)
            return 0;
        for(int i = 0; i < (int)nums.size() - 1; ++i){
            if(nums[i] < target && nums[i + 1] >= target)
                return i + 1;
        }
        return nums.size();
    }
};
*/
