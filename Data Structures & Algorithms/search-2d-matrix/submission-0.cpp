class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // | 1  2  4  8  |
        // | 10 11 12 13 |
        // | 14 20 30 40 |

        int m = matrix.size(); //rows
        int n = matrix[0].size(); //cols

        int top = 0, bottom = m - 1;
        int targetRow = -1;

        //searching for the correct row
        while (top <= bottom) {
            int midRow = top + (bottom - top)/2;

            if (target >= matrix[midRow][0] && target <= matrix[midRow][n-1]) {
                targetRow = midRow;
                break;
            }
            else if (target > matrix[midRow][n-1]) {
                top = midRow + 1;
            } else {
                bottom = midRow - 1;
            }
        }

        if (targetRow == -1) {
            return false;
        }

        int left = 0, right = n - 1;

        //searching for the target
        while (left <= right) {
            int mid = left + (right - left)/2;

            if (target == matrix[targetRow][mid]) {
                return true;
            } else if (target > matrix[targetRow][mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
        
    }
};