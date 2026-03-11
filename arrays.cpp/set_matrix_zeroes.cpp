/*
    Program: Set Matrix Zeroes

    Problem:
    Given an m × n matrix, if any element in the matrix is 0,
    set its entire row and column to 0.

    The modification must be done according to the rule above.

    Example:
    Input Matrix
    1 1 1
    1 0 1
    1 1 1

    Output Matrix
    1 0 1
    0 0 0
    1 0 1


    ---------------------------------------------------------
    1. Brute Force Approach

    Idea:
    Whenever a zero is found, mark its row and column
    with a temporary value (-1e9). After traversal,
    convert all temporary values to 0.

    Why temporary marking?
    Directly placing 0 would incorrectly influence
    other rows and columns during traversal.

    Steps:
    1. Traverse matrix.
    2. If matrix[i][j] == 0:
         mark entire row and column with -1e9.
    3. Traverse again and replace -1e9 with 0.

    Time Complexity: O((m × n) × (m + n))
    Space Complexity: O(1)


    ---------------------------------------------------------
    2. Better Approach (Row and Column Marking)

    Idea:
    Use two extra arrays to track which rows and columns
    must become zero.

    Steps:
    1. Create row[m] and column[n] arrays.
    2. Traverse matrix:
         if matrix[i][j] == 0:
             row[i] = 1
             column[j] = 1
    3. Traverse matrix again:
         if row[i] == 1 or column[j] == 1:
             matrix[i][j] = 0

    Time Complexity: O(m × n)
    Space Complexity: O(m + n)


    ---------------------------------------------------------
    3. Optimal Approach (Constant Space)

    Key Insight:
    Instead of using extra arrays,
    reuse the first row and first column
    of the matrix as markers.

    Steps:
    1. Use matrix[0][j] and matrix[i][0]
       to store whether a row or column
       should become zero.

    2. Use a variable "col0" to track
       if the first column itself needs to be zero.

    3. Traverse matrix and mark rows/columns.

    4. Traverse again and update inner matrix
       based on markers.

    5. Finally update first row and first column.

    Time Complexity: O(m × n)
    Space Complexity: O(1)


    ---------------------------------------------------------
    Concepts Used:
    - Matrix traversal
    - In-place marking
    - Space optimization
*/

#include <iostream>
#include <vector>
using namespace std;

//Brute force approach

void row(int i, int m, int n, vector<vector<int>>& matrix) {
    for (int j = 0; j < n; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1000000000; // same as -1e9
        }
    }
}

void column(int j, int m, int n, vector<vector<int>>& matrix) {
    for (int i = 0; i < m; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1000000000; // same as -1e9
        }
    }
}

void bruteforce(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row(i, m, n, matrix);
                column(j, m, n, matrix);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1000000000) {
                matrix[i][j] = 0;
            }
        }
    }
}

//Better approach
void better(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row(m, 0);
    vector<int> column(n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] == 1 || column[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

//Optimal approach
void optimal(vector<vector<int>>& matrix) {
        int col0 = 1;
        int m = matrix.size();
        int n = matrix[0].size();

        // Use first row and first column as markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        // Set inner matrix elements to 0 based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Set first column
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }



int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    optimal(matrix);

    cout << "Updated matrix:\n";
    for (const auto& r : matrix) {
        for (int val : r) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
