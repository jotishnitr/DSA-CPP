/*
------------------------------------------------------------
Problem: Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/

Pattern Used:
Binary Search on Matrix

Prerequisite:
1. Each row is sorted in ascending order.
2. First element of every row is greater than
   the last element of the previous row.

This means the entire matrix can be treated as
a single sorted 1D array.

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
Perform Binary Search on every row individually.

For each row:
- Apply Binary Search.
- If target is found, return true.

Time Complexity:
O(m × log n)

Space Complexity:
O(1)

------------------------------------------------------------
Optimal Approach

Idea:
Treat the entire matrix as a single sorted array.

Search Space:
low  = 0
high = (m × n) - 1

Convert 1D index into 2D indices:

row = mid / n
col = mid % n

Now compare:

matrix[row][col]

with target exactly like Binary Search.

If matrix[row][col] == target
→ Target found.

If matrix[row][col] < target
→ Search right half.

Else
→ Search left half.

------------------------------------------------------------
Index Mapping

Suppose:

1  3  5
7  9 11
13 15 17

Indices become:

0 1 2
3 4 5
6 7 8

Example:

mid = 5

row = 5 / 3 = 1
col = 5 % 3 = 2

matrix[1][2] = 11

------------------------------------------------------------
Key Observation

Since the whole matrix behaves like one sorted
array, we can perform a single Binary Search
instead of searching row by row.

------------------------------------------------------------
Time Complexity

Brute Force:
O(m × n)

Better:
O(m × log n)

Optimal:
O(log(m × n))

------------------------------------------------------------
Space Complexity

All Approaches:
O(1)

------------------------------------------------------------
Similar Problems

1. Binary Search
2. Search Insert Position
3. Search in Rotated Sorted Array
4. Search a 2D Matrix II
5. Row with Maximum 1s
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

    // Optimal Approach (Binary Search on Entire Matrix)
    bool searchMatrixOptimal(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;

    cout << "Brute Force       : "
         << (obj.searchMatrixBrute(matrix, target) ? "Found" : "Not Found")
         << endl;

    cout << "Better Approach   : "
         << (obj.searchMatrixBetter(matrix, target) ? "Found" : "Not Found")
         << endl;

    cout << "Optimal Approach  : "
         << (obj.searchMatrixOptimal(matrix, target) ? "Found" : "Not Found")
         << endl;

    return 0;
}