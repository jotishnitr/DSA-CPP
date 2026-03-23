/*
    Program: Spiral Matrix Traversal

    Problem:
    Given an m × n matrix, return all elements of the matrix
    in spiral order.

    Spiral order means traversing the matrix layer by layer:
    - Left → Right across the top row
    - Top → Bottom along the right column
    - Right → Left across the bottom row
    - Bottom → Top along the left column

    Continue this process until all elements are visited.

    Example:

    Input Matrix
    1  2  3  4
    5  6  7  8
    9 10 11 12

    Output (Spiral Order)
    1 2 3 4 8 12 11 10 9 5 6 7


    Approach: Boundary Traversal

    Maintain four boundaries:
        top    → first unvisited row
        bottom → last unvisited row
        left   → first unvisited column
        right  → last unvisited column

    Steps:
    1. Traverse from left → right along the top row.
       Increment top.

    2. Traverse from top → bottom along the right column.
       Decrement right.

    3. Traverse from right → left along the bottom row
       (only if top ≤ bottom).
       Decrement bottom.

    4. Traverse from bottom → top along the left column
       (only if left ≤ right).
       Increment left.

    Repeat until all boundaries cross.

    Time Complexity:
        O(m × n)
        Every element is visited exactly once.

    Space Complexity:
        O(1) extra
        (excluding the output vector)

    Edge Cases Handled:
    - Single row matrix
    - Single column matrix
    - Rectangular matrices
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> spiral;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++)
                spiral.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                spiral.push_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    spiral.push_back(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    spiral.push_back(matrix[i][left]);
                left++;
            }
        }

        return spiral;
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);

    cout << "Spiral Order: ";

    for (int num : result)
        cout << num << " ";

    cout << endl;

    return 0;
}