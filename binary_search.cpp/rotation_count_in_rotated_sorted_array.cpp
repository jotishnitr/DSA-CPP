/*
    Problem: Find K Rotation

    Practice Link:
    https://www.geeksforgeeks.org/problems/rotation4723/1

    Pattern Used:
    Binary Search on Rotated Array

    Goal:
    Given a sorted array rotated K times,
    find the value of K.

    Observation:
    The number of rotations is equal to the
    index of the minimum element.

    ---------------------------------------------------------
    Example

    Input:
        arr = [4,5,1,2,3]

    Output:
        2

    Explanation:

        Original Array:
            [1,2,3,4,5]

        After 2 rotations:
            [4,5,1,2,3]

        Minimum element:
            1

        Index of 1:
            2

        Therefore:
            K = 2

    ---------------------------------------------------------
    Core Idea

    This problem is almost identical to:

        Find Minimum in Rotated Sorted Array

    Instead of returning the minimum value,
    return its index.

    ---------------------------------------------------------
    Key Observation

    If:

        arr[low] <= arr[high]

    Then current search space
    is already sorted.

    Therefore:

        arr[low]

    is the minimum element and

        low

    is its index.

    ---------------------------------------------------------
    Case 1

    If:

        arr[low] <= arr[mid]

    Then:

        Left half is sorted.

    Minimum element of this half is:

        arr[low]

    Store it as a candidate and
    search the right half.

    ---------------------------------------------------------
    Case 2

    Otherwise:

        arr[low] > arr[mid]

    Rotation point lies in the left half.

    arr[mid] can be the minimum.

    Store it as a candidate and
    search the left half.

    ---------------------------------------------------------
    Algorithm

    1. Initialize:
            low = 0
            high = n - 1
            ans = INT_MAX
            index = -1

    2. If current range is sorted:
            update answer and index
            break

    3. Compute mid

    4. Check which half is sorted

    5. Update minimum candidate
       and its index

    6. Eliminate one half

    7. Return index

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    Number of rotations
        =
    Index of minimum element

    Therefore:

        Find K Rotations
            ⇔
        Find Minimum Element Index

    ---------------------------------------------------------
    STL Shortcut:
        No direct STL solution exists.

    Custom binary search is required.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& arr) {

        int low = 0;
        int high = arr.size() - 1;

        int ans = INT_MAX;
        int index = -1;

        while (low <= high) {

            if (arr[low] <= arr[high]) {
                if (ans >= arr[low]) {
                    ans = arr[low];
                    index = low;
                }
                break;
            }

            int mid = (low + high) / 2;

            if (arr[low] <= arr[mid]) {

                if (arr[low] <= ans) {
                    ans = arr[low];
                    index = low;
                }

                low = mid + 1;
            }
            else {

                if (arr[mid] <= ans) {
                    ans = arr[mid];
                    index = mid;
                }

                high = mid - 1;
            }
        }

        return index;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {15, 18, 2, 3, 6, 12};

    int rotations = obj.findKRotation(arr);

    cout << "Number of rotations: " << rotations << endl;

    return 0;
}