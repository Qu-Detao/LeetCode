/*
Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        permutations.push_back(nums);

        while(true){
            int i = nums.size() - 1, j = nums.size() - 1;
            while(i > 0 && nums[i] <= nums[i - 1]) --i;
            if(i == 0)  break;
            while(nums[j] <= nums[i - 1])  --j;
            swap(nums[i - 1], nums[j]);
            reverse(nums, i, nums.size() - 1);
            permutations.push_back(nums);
        }
        
        return permutations;
    }

private:
    void reverse(vector<int>& nums, int a, int b){
        while(a < b){
            swap(nums[a++], nums[b--]);
        }
    }
};


/*
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> permutations;
        permute(nums, 0, permutations);

        return permutations;
    }

private:
    void permute(vector<int> nums, int start, vector<vector<int>>& permutations){
        if(start == nums.size() - 1){
            permutations.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); ++i){
            if(i != start && nums[i] == nums[start])  continue;
            swap(nums[start], nums[i]);
            permute(nums, start + 1, permutations);
        }
    }
};
*/
