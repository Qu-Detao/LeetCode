/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n == 0 || k == 0 || n < k)
            return combinations;
        curComb.resize(k);
        combine(1, n, k);
        return combinations;
    }

private:
    vector<int> curComb;
    vector<vector<int>> combinations;
    void combine(int start, int n, int k) {
        while (start <= n - k + 1) {
            curComb[curComb.size() - k] = start++;
            if (k > 1)
                combine(start, n, k - 1);
            else
                combinations.push_back(curComb);
        }
    }
};

/*
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> curComb(k, 0);
        int i = 0;
        while(i >= 0){
            curComb[i]++;
            if(curComb[i] > n)
                --i;
            else if(i == k - 1)
                combinations.push_back(curComb);
            else{
                ++i;
                curComb[i] = curComb[i - 1];
            }
        }
        return combinations;
    }
};
*/
