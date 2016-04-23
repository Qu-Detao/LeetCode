/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        string rs(s.length(), ' ');
        for(size_t i = 0; i < s.length(); ++i)
            rs[i] = s[s.length() - i - 1];
        return rs;
    }
};