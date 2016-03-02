/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. You may assume that each word will 
contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxLen = 0;
        int *bitMap = new int[words.size()];
        sort(words.begin(), words.end(), compareLen);

        for (int i = 0; i < words.size(); ++i) {
            bitMap[i] = str2bits(words[i]);
            for (int j = i - 1; j >= 0; --j)
                if ((bitMap[i] & bitMap[j]) == 0) {
                    maxLen = max(maxLen, int(words[i].length() * words[j].length()));
                    break;
                }
        }

        delete[] bitMap;
        return maxLen;
    }

private:
    static bool compareLen(string s1, string s2) {
        return s1.length() < s2.length();
    }

    int str2bits(string s) {
        int bits = 0;
        for (int i = 0; i < s.length(); ++i)
            bits |= 1 << int(s[i] - 'a');
        return bits;
    }
};
