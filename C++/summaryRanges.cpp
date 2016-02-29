/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for(int i = 0; i < nums.size(); ++i){
            string curRange;
            curRange += to_string(nums[i]);
            int j = i;
            while(nums[j + 1] - nums[j] == 1 && j < nums.size() - 1)
                ++j;
            if(j == i)
                ret.push_back(curRange);
            else{
                curRange += "->" + to_string(nums[j]);
                ret.push_back(curRange);
            }
            i = j;
        }
        return ret;
    }
};
