/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of 
shortest transformation sequence from beginWord to endWord, such that:
1.Only one letter can be changed at a time
2.Each intermediate word must exist in the word list

For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
1.Return 0 if there is no such transformation sequence.
2.All words have the same length.
3.All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.erase(beginWord);
        unordered_set<string> beginSet, endSet, *smallSet, *largeSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
    
        int distance = 1;
        while (!beginSet.empty() && !endSet.empty()) {
            ++distance;
            smallSet = beginSet.size() < endSet.size() ? &beginSet : &endSet;
            largeSet = beginSet.size() < endSet.size() ? &endSet : &beginSet;
    
            unordered_set<string> interSet;
            for (string word : *smallSet) {
                for (int i = 0; i < word.length(); ++i) {
                    char letter = word[i];
                    for (int c = 0; c < 26; ++c) {
                        word[i] = 'a' + c;
                        if (largeSet->find(word) != largeSet->end())
                            return distance;
                        if (wordList.find(word) != wordList.end()) {
                            interSet.insert(word);
                            wordList.erase(word);
                        }
                    }
                    word[i] = letter;
                }
            }
            swap(*smallSet, interSet);
        }
    
        return 0;
    }
};


/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.erase(beginWord);
        wordList.insert(endWord);
        queue<string> toVisit;
        addNeighbors(beginWord, wordList, toVisit);
    
        int distance = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; ++i) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord)
                    return distance;
                addNeighbors(word, wordList, toVisit);
            }
            ++distance;
        }
        return 0;
    }
    
private:
    void addNeighbors(string word, unordered_set<string>& wordList, queue<string>& toVisit) {
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) {
                word[p] = 'a' + k;
                if (wordList.find(word) != wordList.end()) {
                    toVisit.push(word);
                    wordList.erase(word);
                }
            }
            word[p] = letter;
        }
    }
};
*/
