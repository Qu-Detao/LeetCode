/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
        int head = 0, tail = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] == ' ' && s[i] != ' ')
                head = i;
            if (s[i] != ' ')
                tail = i;
        }
        if (head == tail && s[head] == ' ')
            return 0;
        return tail - head + 1;
    }
};
