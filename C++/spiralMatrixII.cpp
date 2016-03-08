/*
Given an integer n, generate a square matrix filled with 
elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int k = 1, i = 0;
        while(k <= n * n){
            int j = i;
            while(j < n - i)
                matrix[i][j++] = k++;
            j = i + 1;
            while(j < n - i)
                matrix[j++][n - 1 - i] = k++;
            j = n - i - 2;
            while(j > i)
                matrix[n - 1 - i][j--] = k++;
            j = n - i - 1;
            while(j > i)
                matrix[j--][i] = k++;
            i++;
        }
        return matrix;
    }
};
