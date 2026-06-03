/*
    Problem: Find Peak Element

    Practice Link:
    https://leetcode.com/problems/find-peak-element/

    Pattern Used:
    Binary Search on Peak / Local Maximum

    Goal:
    Find any peak element in the array and
    return its index.

    Peak Element:
        nums[i] > nums[i-1]
        &&
        nums[i] > nums[i+1]

    Boundary Elements:

        First element is a peak if:
            nums[0] > nums[1]

        Last element is a peak if:
            nums[n-1] > nums[n-2]

    ---------------------------------------------------------
    Example

    Input:
        nums = [1,2,3,1]

    Output:
        2

    Explanation:
        nums[2] = 3

        3 > 2
        3 > 1

        Therefore index 2 is a peak.

    =========================================================
    1. Brute Force Approach

    Idea:
    Check every element and determine whether
    it is greater than both neighbours.

    Steps:

    For every index i:

        left =
            (i == 0)
            ||
            nums[i] > nums[i-1]

        right =
            (i == n-1)
            ||
            nums[i] > nums[i+1]

    If both conditions are true:
        return i

    ---------------------------------------------------------
    Time Complexity:
        O(n)

    Space Complexity:
        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Observation:

    If array is increasing:

        1 2 3 4 5

    A peak must exist on the right side.

    ---------------------------------------------------------

    If array is decreasing:

        5 4 3 2 1

    A peak must exist on the left side.

    ---------------------------------------------------------

    Therefore,
    by observing the slope at mid,
    half of the search space can be discarded.

    ---------------------------------------------------------
    Edge Cases

    1. Single element:
            return 0

    2. First element is peak:
            nums[0] > nums[1]

    3. Last element is peak:
            nums[n-1] > nums[n-2]

    ---------------------------------------------------------
    Peak Check

    If:

        nums[mid] > nums[mid-1]
        &&
        nums[mid] > nums[mid+1]

    Then:

        mid is a peak.

    ---------------------------------------------------------
    Increasing Slope

    If:

        nums[mid] > nums[mid-1]
        &&
        nums[mid] < nums[mid+1]

    Then:

        peak lies on the RIGHT

            low = mid + 1

    ---------------------------------------------------------
    Otherwise

    Peak lies on the LEFT

            high = mid - 1

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We do NOT need the maximum element.

    We only need ANY peak element.

    By checking the slope around mid,
    one side can always be safely discarded.

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

    // Brute Force Approach
    int findPeakElementBrute(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool left = (i == 0) || (nums[i] > nums[i - 1]);
            bool right = (i == n - 1) || (nums[i] > nums[i + 1]);

            if (left && right) {
                return i;
            }
        }

        return -1;
    }

    // Optimal Binary Search Approach
    int findPeakElementOptimal(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return 0;

        if (nums[0] > nums[1]) return 0;

        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1]) {
                return mid;
            }

            else if (nums[mid] > nums[mid - 1] &&
                     nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 2, 3, 1};

    int bruteAns = obj.findPeakElementBrute(nums);
    int optimalAns = obj.findPeakElementOptimal(nums);

    cout << "Brute Force Peak Index : "
         << bruteAns
         << ", Value : "
         << nums[bruteAns]
         << endl;

    cout << "Optimal Peak Index     : "
         << optimalAns
         << ", Value : "
         << nums[optimalAns]
         << endl;

    return 0;
}