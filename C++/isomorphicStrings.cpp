/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char sMap[128] = { 0 };
        char tMap[128] = { 0 };
        for (int i = 0; i < s.size(); ++i){
            if (sMap[s[i]] != tMap[t[i]]) 
                return false;
            sMap[s[i]] = i + 1;
            tMap[t[i]] = i + 1;
        }
        return true;    
    }
};
