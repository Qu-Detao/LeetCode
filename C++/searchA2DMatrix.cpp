/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / cols][mid % cols] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return matrix[right / cols][right % cols] == target;
    }
};

/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] < target)
                ++i;
            else if (matrix[i][j]>target)
                --j;
            else
                return true;
        }
        return false;
    }
};
*/
