/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
1.Each element in the result must be unique.
2.The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_set<int> numSet(nums1.begin(), nums1.end());
        
        for(int num : nums2){
            if(numSet.erase(num))
                ret.push_back(num);
        }
        
        return ret;
    }
};
