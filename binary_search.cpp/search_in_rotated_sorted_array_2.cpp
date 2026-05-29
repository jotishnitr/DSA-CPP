/*
    Problem: Search in Rotated Sorted Array II

    Practice Link:
    https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

    Pattern Used:
    Binary Search on Rotated Array with Duplicates

    Goal:
    Given a rotated sorted array that may contain duplicates,
    determine whether the target exists.

    Return:
        true  -> target found
        false -> target not found

    ---------------------------------------------------------
    Example

    Input:
        nums = [2,5,6,0,0,1,2]
        target = 0

    Output:
        true

    ---------------------------------------------------------
    Difference from Rotated Sorted Array I

    Previous Problem:
        All elements were unique.

    This Problem:
        Duplicate values are allowed.

    Because of duplicates,
    identifying the sorted half is sometimes impossible.

    ---------------------------------------------------------
    Ambiguous Case

    Example:

        [1,0,1,1,1]

    low = 0
    mid = 2
    high = 4

        nums[low]  = 1
        nums[mid]  = 1
        nums[high] = 1

    We cannot determine which half is sorted.

    ---------------------------------------------------------
    Handling Duplicates

    If:

        nums[low] == nums[mid]
        &&
        nums[mid] == nums[high]

    Then:

        low++
        high--

    Shrink the search space and continue.

    ---------------------------------------------------------
    Identifying Sorted Half

    Case 1:

        nums[mid] <= nums[high]

    Right half is sorted.

    Check whether target lies in:

        [nums[mid], nums[high]]

    ---------------------------------------------------------
    Case 2:

        nums[mid] > nums[high]

    Left half is sorted.

    Check whether target lies in:

        [nums[low], nums[mid]]

    ---------------------------------------------------------
    Time Complexity

    Average Case:
        O(log n)

    Worst Case:
        O(n)

    Reason:
        Duplicate values may force us to
        shrink the search space one step at a time.

    Example:

        [1,1,1,1,1,1,1]

    ---------------------------------------------------------
    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    Rotated Array I:
        One half is always identifiable.

    Rotated Array II:
        Duplicates can hide the sorted half.

    Therefore:
        Remove ambiguity first
        then apply normal rotated-array binary search.

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
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Cannot determine sorted half due to duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Right half is sorted
            if (nums[mid] <= nums[high]) {

                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            // Left half is sorted
            else {

                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool result = obj.search(nums, target);

    if (result) {
        cout << "Target found" << endl;
    }
    else {
        cout << "Target not found" << endl;
    }

    return 0;
}