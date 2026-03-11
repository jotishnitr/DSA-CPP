/*
    Program: Rotate Matrix by 90 Degrees (Clockwise)

    Problem:
    Given an n × n matrix, rotate the matrix by 90 degrees
    in the clockwise direction.

    The rotation must be done in-place, meaning we cannot
    use another matrix for storing the result.

    Example:

    Input Matrix
    1 2 3
    4 5 6
    7 8 9

    Output Matrix (90° Clockwise Rotation)
    7 4 1
    8 5 2
    9 6 3


    Optimal Approach

    Key Idea:
    A 90° clockwise rotation can be achieved in two steps:

    1. Transpose the matrix
       Convert rows into columns.

       Example:
       1 2 3       1 4 7
       4 5 6  →    2 5 8
       7 8 9       3 6 9

    2. Reverse each row
       Reverse elements of every row.

       Example:
       1 4 7       7 4 1
       2 5 8  →    8 5 2
       3 6 9       9 6 3


    Why This Works

    Transpose swaps elements across the diagonal:
        matrix[i][j] ↔ matrix[j][i]

    Reversing rows then shifts elements to their correct
    rotated positions.

    Time Complexity:
        O(n²)

    Space Complexity:
        O(1)
        (rotation is done in-place)

    Constraints:
    - Matrix must be square (n × n).
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Optimal Approach
void optimal(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    optimal(matrix);

    cout << "Rotated Matrix:\n";
    printMatrix(matrix);

    return 0;
}