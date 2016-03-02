/*
Given an array of integers, every element appears three 
times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(int c : nums){
            int ta = (~a & b & c) | (a & ~b & ~c);
            b = (~a & ~b & c) | (~a & b & ~c);
            a = ta;
        }
        
        return a|b;
    }
};

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        int bit, sum;
        for(int i = 0; i < 32; ++i){
            sum = 0;
            bit = 1 << i;
            for(int j = 0; j < nums.size(); ++j)
                if(bit & nums[j])
                    ++sum;
            if(sum % 3)
                single |= bit;
        }
        
        return single;
    }
};
*/
