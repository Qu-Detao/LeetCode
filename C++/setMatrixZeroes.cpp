/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
    
        for (int i = (int)matrix.size() - 1; i >= 0; --i) {
            for (int j = (int)matrix[0].size() - 1; j >= 1; --j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
