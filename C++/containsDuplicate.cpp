/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) 
            return false;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i+1]) 
                return true;
        }
    return false;
    }
};

/*
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};
*/

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, size_t> integer_count;
        for(int v : nums){
            ++integer_count[v];
            if(integer_count[v] > 1)
                return true;
        }
        return false;
    }
};
*/
