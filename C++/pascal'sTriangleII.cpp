/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curRow(rowIndex + 1, 1);
        for(int row = 0; row < rowIndex; ++row) {
            for(int col = row; col > 0; --col) {
                curRow[col] += curRow[col - 1];
            }
        }
        return curRow;
    }
};

/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curRow(rowIndex + 1, 1);
        int mid = rowIndex / 2;
        for(int i = 1; i <= mid; ++i){
            curRow[i] = curRow[rowIndex - i] = comb(rowIndex, i);
        }

        return curRow;
    }

private:
    int comb(int a, int b){
        int64_t comb = 1;
        for(int i = 0; i < b; ++i){
            comb *= a - i;
            comb /= i + 1;
        }
        return int(comb);
    }
};
*/
