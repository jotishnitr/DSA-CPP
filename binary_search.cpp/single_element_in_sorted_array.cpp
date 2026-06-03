/*
    Problem: Single Element in a Sorted Array

    Practice Link:
    https://leetcode.com/problems/single-element-in-a-sorted-array/

    Pattern Used:
    Binary Search on Index Parity

    Goal:
    Given a sorted array where every element appears
    exactly twice except one element which appears once,
    find that single element.

    Example:

    Input:
        nums = [1,1,2,3,3,4,4,8,8]

    Output:
        2

    ---------------------------------------------------------
    Observation

    Before the single element:

        Pairs start at even indices.

        [1,1] [2,2] [3,3]

         0 1   2 3   4 5

    First occurrence of every pair
    is at an EVEN index.

    ---------------------------------------------------------
    After the single element:

        Pair alignment shifts.

        [3,3] [4,4]

         3 4   5 6

    First occurrence of every pair
    is now at an ODD index.

    ---------------------------------------------------------
    Core Idea

    Use binary search to determine
    which side contains the single element.

    ---------------------------------------------------------
    Edge Cases

    1. Array contains only one element.

    2. First element is the answer.

    3. Last element is the answer.

    These are handled before binary search.

    ---------------------------------------------------------
    Middle Element Check

    If:

        nums[mid] != nums[mid-1]
        &&
        nums[mid] != nums[mid+1]

    Then:

        nums[mid]

    is the single element.

    ---------------------------------------------------------
    Left Half is Properly Paired

    If:

        mid is even
        &&
        nums[mid] == nums[mid+1]

    OR

        mid is odd
        &&
        nums[mid] == nums[mid-1]

    Then:

        all elements up to mid
        are correctly paired.

    Single element lies on the RIGHT.

        low = mid + 1

    ---------------------------------------------------------
    Pair Structure Broken

    Otherwise:

        single element lies on the LEFT.

        high = mid - 1

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    Before the single element:
        Pair starts at EVEN index

    After the single element:
        Pair starts at ODD index

    This parity change allows binary search.

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
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (nums[0] != nums[1]) {
            return nums[0];
        }

        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {

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

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    int result = obj.singleNonDuplicate(nums);

    cout << "Single non-duplicate element: "
         << result << endl;

    return 0;
}