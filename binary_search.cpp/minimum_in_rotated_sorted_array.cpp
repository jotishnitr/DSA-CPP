/*
    Problem: Find Minimum in Rotated Sorted Array

    Practice Link:
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

    Pattern Used:
    Binary Search on Rotated Array

    Goal:
    Given a rotated sorted array with unique elements,
    find the minimum element.

    Example:

    Input:
        nums = [4,5,6,7,0,1,2]

    Output:
        0

    ---------------------------------------------------------
    Observation

    A rotated sorted array consists of:

        Sorted Part 1 + Sorted Part 2

    Example:

        [4,5,6,7,0,1,2]

    The minimum element is the rotation point.

    ---------------------------------------------------------
    Key Optimization

    If:

        nums[low] <= nums[high]

    Then the current search space
    is already sorted.

    Therefore:

        nums[low]

    is the minimum element of that range.

    Update answer and stop searching.

    ---------------------------------------------------------
    Core Idea

    At every step,
    one half is guaranteed to be sorted.

    If left half is sorted:

        nums[low] <= nums[mid]

    Then:
        nums[low] is the minimum element
        of that half.

    Store it as a candidate and
    search the right half.

    ---------------------------------------------------------
    Otherwise:

        nums[low] > nums[mid]

    Rotation point lies in the left half.

    nums[mid] can be the minimum.

    Store it as a candidate and
    search the left half.

    ---------------------------------------------------------
    Algorithm

    1. Initialize:
            low = 0
            high = n - 1
            ans = INT_MAX

    2. If current range is sorted:
            update answer
            break

    3. Compute mid

    4. Check whether left half is sorted

    5. Update minimum candidate

    6. Eliminate one half

    7. Repeat

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    When a half is sorted:

        The first element of that half
        is its minimum.

    This allows us to discard
    half of the search space.

    ---------------------------------------------------------
    Why the Early Exit Works

    If:

        nums[low] <= nums[high]

    Then the subarray is already sorted.

    Since the first element of a sorted array
    is always the smallest,

        nums[low]

    is the minimum of that entire range.

    No further binary search is needed.

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
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {

            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = (low + high) / 2;

            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else {
                ans = min(nums[mid], ans);
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int result = obj.findMin(nums);

    cout << "Minimum element: " << result << endl;

    return 0;
}

