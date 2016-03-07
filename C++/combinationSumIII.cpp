/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination 
should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allCombs;
        vector<int> comb;
        combinationSum(allCombs, comb, k, n);
        
        return allCombs;
    }

private:
    void combinationSum(vector<vector<int>>& allCombs, vector<int>& comb, int k, int n){
        if(comb.size() == k && n == 0){
            allCombs.push_back(comb);
            return;
        }
        if(comb.size() < k){
            for(int i = comb.empty() ? 1 : comb.back() + 1; i <= 9; ++i){
                if(n - i < 0)   break;
                comb.push_back(i);
                combinationSum(allCombs, comb, k, n - i);
                comb.pop_back();
            }
        }    
    }
};
