/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it = nums.begin(); it != nums.end(); ++it){
            if(*it == val){
                nums.erase(it);
                --it;
            }
        }
        return nums.size();
    }
};