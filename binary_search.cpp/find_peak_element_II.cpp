/*
------------------------------------------------------------
Problem: Find a Peak Element II
Link: https://leetcode.com/problems/find-a-peak-element-ii/

Pattern Used:
Binary Search on Columns

Prerequisite:
A peak element is greater than all of its
adjacent neighbors (up, down, left, right).

------------------------------------------------------------
Brute Force Approach

Idea:
Traverse every element in the matrix.

For each cell:
- Compare it with its four neighbors.
- If it is greater than all valid neighbors,
  return its position.

Time Complexity:
O(m × n)

Space Complexity:
O(1)

------------------------------------------------------------
Optimal Approach

Idea:
Perform Binary Search on columns.

For every middle column:
1. Find the row containing the maximum element
   in that column.
2. Compare this element with its left and
   right neighbors.

If current element is greater than both,
it is a peak.

Otherwise:
- If right neighbor is greater,
  search the right half.
- Else,
  search the left half.

------------------------------------------------------------
Helper Function

rowFun(mat, m, col)

Returns the row index containing the maximum
element in the given column.

Time Complexity:
O(m)

------------------------------------------------------------
Binary Search

Search Space:

low  = 0
high = n - 1

For every middle column:

Find:

row = rowFun(mat, m, mid)

Compare:

current = mat[row][mid]
left    = mat[row][mid-1]
right   = mat[row][mid+1]

If current > left && current > right
→ Peak Found.

Else if current < right
→ Search Right Half.

Else
→ Search Left Half.

------------------------------------------------------------
Why Only Left and Right?

Since current is already the maximum element
in its column,

It is guaranteed to be greater than
or equal to its upper and lower neighbors.

Therefore,
only left and right neighbors need to be checked.

------------------------------------------------------------
Dry Run

Matrix

10 20 15
21 30 14
7  16 32

mid = 1

Maximum in Column 1 = 30

Left = 21
Right = 14

30 > 21
30 > 14

Peak Found

Answer = (1,1)

------------------------------------------------------------
Key Observation

For every column,
choosing the maximum element guarantees that
moving vertically cannot produce a larger value.

Hence Binary Search only needs to decide
whether to move left or right.

------------------------------------------------------------
Time Complexity

Brute Force:
O(m × n)

Optimal:
O(m × log n)

where:

O(m)      -> Find maximum element in one column
O(log n)  -> Binary Search on columns

------------------------------------------------------------
Space Complexity

Both Approaches:
O(1)

------------------------------------------------------------
Similar Problems

1. Find Peak Element
2. Peak Index in Mountain Array
3. Search a 2D Matrix
4. Search a 2D Matrix II
5. Binary Search on Matrix
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // Brute Force Approach
    vector<int> findPeakGridBrute(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int up    = (i > 0)     ? mat[i - 1][j] : -1;
                int down  = (i < m - 1) ? mat[i + 1][j] : -1;
                int left  = (j > 0)     ? mat[i][j - 1] : -1;
                int right = (j < n - 1) ? mat[i][j + 1] : -1;

                if (mat[i][j] > up &&
                    mat[i][j] > down &&
                    mat[i][j] > left &&
                    mat[i][j] > right) {

                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }

    // Returns row having maximum element in a column
    int rowFun(vector<vector<int>>& mat, int m, int col) {

        int largest = INT_MIN;
        int row = 0;

        for (int i = 0; i < m; i++) {

            if (mat[i][col] > largest) {
                largest = mat[i][col];
                row = i;
            }
        }

        return row;
    }

    // Optimal Approach (Binary Search)
    vector<int> findPeakGridOptimal(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int row = rowFun(mat, m, mid);

            int left  = (mid > 0)     ? mat[row][mid - 1] : -1;
            int right = (mid < n - 1) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left &&
                mat[row][mid] > right) {

                return {row, mid};
            }
            else if (mat[row][mid] < right) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> brute = obj.findPeakGridBrute(mat);
    vector<int> optimal = obj.findPeakGridOptimal(mat);

    cout << "Brute Force Peak : ("
         << brute[0] << ", " << brute[1] << ")\n";

    cout << "Optimal Peak     : ("
         << optimal[0] << ", " << optimal[1] << ")\n";

    return 0;
}