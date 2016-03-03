/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> treeNums(n + 1, 0);
        treeNums[0] = treeNums[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j < i / 2; ++j)
                treeNums[i] += 2 * treeNums[j] * treeNums[i - 1 - j];
            if (i % 2)
                treeNums[i] += treeNums[i / 2] * treeNums[i / 2];
        }
        return treeNums[n];
    }
};


/*
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1)  return 1;
        int num = 0;
        for(int i = 0; i < n / 2; ++i)
            num += 2 * numTrees(i) * numTrees(n - 1 - i);
        if(n % 2)
            num += numTrees(n / 2) * numTrees(n / 2);
        return num;
    }
};
*/
