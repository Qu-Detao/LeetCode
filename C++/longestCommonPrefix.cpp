/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int lenPrefix = 0;
        for (int i = 0; i < strs[0].length(); ++i) {
            char curChar = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != curChar){
                    if(lenPrefix == 0)
                        return "";
                    return strs[0].substr(0, lenPrefix);
                }
            }
            ++lenPrefix;
        }
    
        return strs[0].substr(0, lenPrefix);
    }
};
