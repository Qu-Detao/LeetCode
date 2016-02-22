/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if(numRows == 0)
            return triangle;
        triangle.push_back(vector<int> (1, 1));
        for(int i = 1; i < numRows; ++i){
            vector<int> curRow(i + 1, 1);
            int mid = i / 2;
            for(int j = 1; j <= mid; ++j){
                curRow[j] = curRow[i - j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(curRow);
        }
        return triangle;
    }
};

/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i = 0; i < numRows; ++i){
            vector<int> curRow(i + 1, 1);
            int mid = i / 2;
            for(int j = 1; j <= mid; ++j){
                curRow[j] = curRow[i - j] = comb(i, j);
            }
            triangle.push_back(curRow);
        }
        return triangle;
    }

private:
    int comb(int a, int b){
        int64_t den = 1, num = 1;
        for(int i = 0; i < b; ++i){
            den *= a - i;
            num *= i + 1;
        }
        return int(den / num);
    }
};
*/
