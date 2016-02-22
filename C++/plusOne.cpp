/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while(i >= 0){
            int cur = digits[i] + 1;
            if(cur == 10){
                digits[i] = 0;
                --i;
            } else {
                digits[i] = cur;
                break;
            }
        }
        if(i == -1)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};