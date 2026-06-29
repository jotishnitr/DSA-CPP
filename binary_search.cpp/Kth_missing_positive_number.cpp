/*
    Problem: Kth Missing Positive Number

    Practice Link:
    https://leetcode.com/problems/kth-missing-positive-number/

    Pattern Used:
    Binary Search on Index Property

    Goal:
    Given a sorted array of positive integers,
    find the kth missing positive number.

    ---------------------------------------------------------
    Example

    Input:

        arr = [2,3,4,7,11]
        k = 5

    Missing Numbers:

        1, 5, 6, 8, 9, 10, ...

    5th Missing Number:

        9

    Output:

        9

    =========================================================
    Key Observation

    In a perfect sequence:

        Index : 0 1 2 3 4
        Value : 1 2 3 4 5

    Missing numbers before index i:

        arr[i] - (i + 1)

    ---------------------------------------------------------
    Example

        arr = [2,3,4,7,11]

        Index  Value   Missing

          0      2        1
          1      3        1
          2      4        1
          3      7        3
          4      11       6

    Formula:

        missing =
            arr[i] - (i + 1)

    =========================================================
    1. Brute Force Approach

    Idea

    Traverse array and adjust k.

    ---------------------------------------------------------
    Logic

    If:

        arr[i] <= k

    Then:

        One missing number lies before
        or at this position.

        Increase k.

    ---------------------------------------------------------
    Example

        arr = [2,3,4,7,11]
        k = 5

        2 <= 5  -> k = 6
        3 <= 6  -> k = 7
        4 <= 7  -> k = 8
        7 <= 8  -> k = 9

        Answer = 9

    ---------------------------------------------------------
    Time Complexity:
        O(n)

    Space Complexity:
        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    We need to find the first position
    where:

        missing >= k

    ---------------------------------------------------------
    Missing Count Formula

        missing =
            arr[mid] - (mid + 1)

    ---------------------------------------------------------
    Binary Search Condition

    If:

        missing < k

    Then:

        kth missing number lies on the right.

            low = mid + 1

    ---------------------------------------------------------

    If:

        missing >= k

    Then:

        kth missing number lies on the left.

            high = mid - 1

    =========================================================
    Derivation of Answer

    After binary search:

        high = last index where

            missing < k

    We know:

        missing = arr[high] - (high + 1)

    ---------------------------------------------------------

    Let:

        more = remaining missing numbers
             = k - missing

    Answer will be:

        arr[high] + more

    ---------------------------------------------------------

    answer

        = arr[high] + (k - missing)

        = arr[high] +
          (k - (arr[high] - (high + 1)))

        = arr[high] +
          (k - arr[high] + high + 1)

        = high + k + 1

    ---------------------------------------------------------

    Therefore:

        answer = high + k + 1

    Equivalent Form:

        answer = low + k

    because:

        low = high + 1

    =========================================================
    Example

        arr = [2,3,4,7,11]
        k = 5

    Binary Search Ends:

        high = 3

    Answer:

        high + k + 1

        = 3 + 5 + 1

        = 9

    =========================================================
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are not searching for the missing number directly.

    We are searching for the boundary where:

        missing count >= k

    This makes it a:

        Binary Search on Index Property

    problem.

    ---------------------------------------------------------
    STL Shortcut:
        No direct STL solution exists.

    Custom binary search is required.
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Brute Force (Linear Search)
    int findKthPositiveBrute(vector<int>& arr, int k) {

        int n = arr.size();

        for (int i = 0; i < n; i++) {

            if (arr[i] <= k) {
                k++;
            }
            else {
                break;
            }
        }

        return k;
    }

    // Optimal (Binary Search)
    int findKthPositiveOptimal(vector<int>& arr, int k) {

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return high + 1 + k;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "Brute Force Answer  : "
         << obj.findKthPositiveBrute(arr, k)
         << endl;

    cout << "Binary Search Answer: "
         << obj.findKthPositiveOptimal(arr, k)
         << endl;

    return 0;
}