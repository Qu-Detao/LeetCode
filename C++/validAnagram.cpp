/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> S(26, 0), T(26, 0);
        for(auto v : s) S[int(v) - int('a')]++;
        for(auto v : t) T[int(v) - int('a')]++;
        for(int i = 0; i < 26; ++i){
            if(S[i] != T[i])
                return false;
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        for(size_t i = 0; i < s.length(); ++i){
            string::size_type pos = t.find(s[i]);
            if(pos == string::npos)
                return false;
            else
                t.erase(pos, 1);
        }
        return true;
    }
};
*/
