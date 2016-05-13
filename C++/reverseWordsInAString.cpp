/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

Clarification:
1. What constitutes a word?
   A sequence of non-space characters constitutes a word.
2. Could the input string contain leading or trailing spaces?
   Yes. However, your reversed string should not contain leading or trailing spaces.
3. How about multiple spaces between two words?
   Reduce them to a single space in the reversed string.
*/

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                if (index != 0)  s[index++] = ' ';
                int j = i;
                while (j < s.length() && s[j] != ' ')
                    s[index++] = s[j++];
                reverse(s.begin() + index - (j - i), s.begin() + index);
                i = j;
            }
        }
        s.erase(s.begin() + index, s.end());
    }
};


/*
class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        for (int i = 0; i < s.length(); ++i) {
            while (isspace(s[i]) && i < s.length())    ++i;
            string curWord = "";
            while (!isspace(s[i]) && i < s.length()) {
                curWord += s[i];
                ++i;
            }
            if(!curWord.empty())
                words.push_back(curWord);
        }
    
        s = "";
        for (int i = words.size() - 1; i > 0; --i)
            s += words[i] + ' ';
        if(!words.empty())
            s += words[0];
        cout << s << endl;
    }
};
*/
