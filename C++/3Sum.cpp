/*
Given an array S of n integers, are there elements a, b, c in S 
such that a + b + c = 0? Find all unique triplets in the array 
which gives the sum of zero.

Note:
1. Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
2. The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},
A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if(nums.size() < 3) return results;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i){
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
                int j = i + 1, k = nums.size() - 1;
                while(j < k){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        results.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j + 1])  ++j;
                        while(j < k && nums[k] == nums[k - 1])  --k;
                        ++j, --k;
                    } else if (nums[i] + nums[j] + nums[k] < 0) ++j;
                    else --k;
                }
            }
        }
        return results;
    }
};
