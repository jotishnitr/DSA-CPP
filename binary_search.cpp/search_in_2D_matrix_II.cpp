/*
------------------------------------------------------------
Problem: Search a 2D Matrix II
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

Pattern Used:
Matrix Traversal + Binary Search Logic

Prerequisite:
1. Every row is sorted in ascending order.
2. Every column is sorted in ascending order.

Unlike Search a 2D Matrix I,
the entire matrix is NOT globally sorted,
so we cannot treat it as a 1D sorted array.

------------------------------------------------------------
Brute Force Approach

Idea:
Traverse every element of the matrix and compare
it with the target.

Time Complexity:
O(m × n)

Space Complexity:
O(1)

------------------------------------------------------------
Better Approach

Idea:
Since every row is sorted,
perform Binary Search on each row.

For every row:
- Apply Binary Search.
- If target is found, return true.

Time Complexity:
O(m × log n)

Space Complexity:
O(1)

------------------------------------------------------------
Optimal Approach

Idea:
Start from the top-right corner.

Initial Position:
row = 0
col = n - 1

At every step:

If matrix[row][col] == target
→ Target found.

If matrix[row][col] < target
→ Entire current row on the left is smaller.
→ Move Down.
→ row++

If matrix[row][col] > target
→ Entire current column below is larger.
→ Move Left.
→ col--

Continue until:
row == m
or
col < 0

------------------------------------------------------------
Why Top-Right Corner?

At the top-right element:

Left  ← Smaller Elements
Down  ↓ Larger Elements

Therefore:

Current < Target
→ Move Down

Current > Target
→ Move Left

Each move eliminates one complete row
or one complete column.

------------------------------------------------------------
Dry Run

Matrix:

1   4   7   11   15
2   5   8   12   19
3   6   9   16   22
10 13 14   17   24
18 21 23   26   30

Target = 16

Start:
15

15 < 16
Move Down

19

19 > 16
Move Left

12

12 < 16
Move Down

16

Found

------------------------------------------------------------
Key Observation

From the top-right corner:

Move Left
→ Remove an entire column.

Move Down
→ Remove an entire row.

Hence every step discards one row or one
column, giving linear complexity.

------------------------------------------------------------
Time Complexity

Brute Force:
O(m × n)

Better:
O(m × log n)

Optimal:
O(m + n)

------------------------------------------------------------
Space Complexity

All Approaches:
O(1)

------------------------------------------------------------
Similar Problems

1. Search a 2D Matrix
2. Row with Maximum 1s
3. Binary Search in Matrix
4. Staircase Search
5. Matrix Search Problems
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Brute Force Approach
    bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }

        return false;
    }

    // Better Approach (Binary Search on Every Row)
    bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {

            int low = 0;
            int high = n - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (matrix[i][mid] == target) {
                    return true;
                }
                else if (matrix[i][mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }

    // Optimal Approach (Top-Right Corner Search)
    bool searchMatrixOptimal(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                row++;
            }
            else {
                col--;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 16;

    cout << "Brute Force      : "
         << (obj.searchMatrixBrute(matrix, target) ? "Found" : "Not Found")
         << endl;

    cout << "Better Approach  : "
         << (obj.searchMatrixBetter(matrix, target) ? "Found" : "Not Found")
         << endl;

    cout << "Optimal Approach : "
         << (obj.searchMatrixOptimal(matrix, target) ? "Found" : "Not Found")
         << endl;

    return 0;
}