/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2)
            return false;
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (stk.size() == 0 || (s[i] == ')' && stk.top() != '(') ||
                (s[i] == ']' && stk.top() != '[') ||
                (s[i] == '}' && stk.top() != '{'))
                return false;
            else
                stk.pop();
        }
        return stk.size() ? false : true;
    }
};
