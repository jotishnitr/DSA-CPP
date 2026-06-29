/*
------------------------------------------------------------
Problem: Median in a Row Wise Sorted Matrix
Link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

Pattern Used:
Binary Search on Answer

Prerequisite:
1. Every row of the matrix is sorted.
2. Total number of elements is odd.

------------------------------------------------------------
Brute Force Approach

Idea:
- Store all elements in a 1D array.
- Sort the array.
- Return the middle element.

Time Complexity:
O((m × n) log(m × n))

Space Complexity:
O(m × n)

------------------------------------------------------------
Optimal Approach

Idea:
Instead of searching for the median directly,
Binary Search on the value of the median.

Search Space:

low  = minimum first element among all rows
high = maximum last element among all rows

For every middle value (mid),
count how many elements are less than or equal
to mid.

If count <= requiredElements
→ Median is larger.
→ Search Right Half.

Else
→ Median is smaller or equal.
→ Search Left Half.

------------------------------------------------------------
Helper Function

ub(arr, x)

Returns the index of the first element
greater than x (Upper Bound).

This index is also equal to the number of
elements less than or equal to x.

Example:

arr = [1,3,5,7]
x = 5

Upper Bound = 3

Elements <= 5 = 3

------------------------------------------------------------
Helper Function

smallerEqual(mat, x)

For every row:
Count elements <= x using Upper Bound.

Total count gives the number of elements
less than or equal to x in the matrix.

------------------------------------------------------------
Binary Search

Required Position:

req = (rows × cols) / 2

While(low <= high)

mid = low + (high - low) / 2

count = smallerEqual(matrix, mid)

If count <= req
→ Median lies on the right.
→ low = mid + 1

Else
→ Median lies on the left.
→ high = mid - 1

Answer = low

------------------------------------------------------------
Dry Run

Matrix

1 3 5
2 6 9
3 6 9

Search Space

low = 1
high = 9

req = 4

mid = 5

Elements <= 5

Row1 -> 3
Row2 -> 1
Row3 -> 1

Count = 5

5 > 4

Search Left

Eventually:

Answer = 5

------------------------------------------------------------
Key Observation

The median is the smallest number having
more than half of the matrix elements
less than or equal to it.

Since increasing the candidate value
always increases (or keeps) the count of
elements <= candidate,

the search space is monotonic,
making Binary Search possible.

------------------------------------------------------------
Time Complexity

Brute Force:
O((m × n) log(m × n))

Optimal:
O(log(maxValue - minValue) × m × log n)

where

O(log(maxValue - minValue))
→ Binary Search on answer

O(m × log n)
→ Upper Bound in every row

------------------------------------------------------------
Space Complexity

Brute Force:
O(m × n)

Optimal:
O(1)

------------------------------------------------------------
Similar Problems

1. Kth Smallest Element in a Sorted Matrix
2. Row with Maximum 1s
3. Search a 2D Matrix
4. Find Median from Data Stream
5. Binary Search on Answer
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    // Brute Force Approach
    int medianBrute(vector<vector<int>>& mat) {

        vector<int> temp;

        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp.push_back(mat[i][j]);
            }
        }

        sort(temp.begin(), temp.end());

        return temp[(n * m) / 2];
    }

    // Upper Bound
    int ub(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }

    // Count elements <= x
    int smallerEqual(vector<vector<int>>& mat, int x) {

        int count = 0;

        for (int i = 0; i < mat.size(); i++) {
            count += ub(mat[i], x);
        }

        return count;
    }

    // Optimal Approach
    int medianOptimal(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int req = (n * m) / 2;

        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int smallerEquals = smallerEqual(mat, mid);

            if (smallerEquals <= req) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Brute Force Median  : "
         << obj.medianBrute(mat)
         << endl;

    cout << "Binary Search Median: "
         << obj.medianOptimal(mat)
         << endl;

    return 0;
}