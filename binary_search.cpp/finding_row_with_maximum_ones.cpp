/*
------------------------------------------------------------
Problem: Row with Maximum 1s
Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

Pattern Used:
Binary Search on Each Row

Prerequisite:
Each row of the matrix is sorted
(0s followed by 1s).

Intuition:
The row containing the maximum number of 1s
will have the leftmost occurrence of the first 1.

For each row:
- Find the first occurrence of 1 using Binary Search.
- Number of 1s = columns - firstOneIndex.
- Track the row having the maximum number of 1s.

Helper Function:
lowerBound(arr)

Returns the index of the first occurrence of 1
in the given row.

Logic:
If arr[mid] >= 1
→ Store answer
→ Search in left half

Else
→ Search in right half

Brute Force:
- Traverse every element.
- Count number of 1s in every row.
- Return the row having maximum count.

Time Complexity:
O(n × m)

Space Complexity:
O(1)

Optimal Approach:
For every row:
- Find first 1 using Binary Search.
- Count ones = m - firstOneIndex.
- Update answer if current row has more 1s.

Time Complexity:
O(n × log m)

Space Complexity:
O(1)

Key Observation:
Since every row is sorted,
finding the first occurrence of 1 gives the
count of 1s directly.

Formula:
ones = totalColumns - firstOneIndex

Similar Problems:
1. Count 1s in a Sorted Binary Array
2. First Occurrence using Binary Search
3. Lower Bound
------------------------------------------------------------
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int lowerBound(vector<int>& arr) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] >= 1) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    // Brute Force
    int rowWithMax1sBrute(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int maxOnes = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    count++;
            }

            if (count > maxOnes) {
                maxOnes = count;
                index = i;
            }
        }

        return index;
    }

    // Optimal
    int rowWithMax1sOptimal(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int maxOnes = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {

            int firstOne = lowerBound(mat[i]);
            int ones = m - firstOne;

            if (ones > maxOnes) {
                maxOnes = ones;
                index = i;
            }
        }

        return index;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat = {
        {0,0,1,1},
        {0,1,1,1},
        {0,0,0,1},
        {1,1,1,1}
    };

    cout << "Brute Force Answer  : "
         << obj.rowWithMax1sBrute(mat) << endl;

    cout << "Binary Search Answer: "
         << obj.rowWithMax1sOptimal(mat) << endl;

    return 0;
}