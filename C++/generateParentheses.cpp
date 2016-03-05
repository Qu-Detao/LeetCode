/*
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateParenthesis(ret, "", n, n);
        return ret;
    }

private:
    void generateParenthesis(vector<string> &ret, string str, int left, int right){
        if(left == 0 && right == 0){
            ret.push_back(str);
            return;
        }
        if(left > 0)
            generateParenthesis(ret, str + "(", left - 1, right);
        if(right > left)
            generateParenthesis(ret, str + ")", left, right - 1);
    }
};
