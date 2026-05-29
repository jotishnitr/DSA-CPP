/*
    Problem: Search in Rotated Sorted Array

    Practice Link:
    https://leetcode.com/problems/search-in-rotated-sorted-array/

    Pattern Used:
    Binary Search on Rotated Array

    Goal:
    Given a rotated sorted array and a target,
    return its index if found.
    Otherwise return -1.

    Example:

    Input:
        nums = [4,5,6,7,0,1,2]
        target = 0

    Output:
        4

    ---------------------------------------------------------
    Core Idea

    A rotated sorted array always has
    one half sorted.

    At every step:
        - Identify the sorted half
        - Check if target lies inside it
        - Eliminate the other half

    ---------------------------------------------------------
    How to Identify Sorted Half

    Case 1:
        nums[mid] <= nums[high]

    Then:
        Right half is sorted

        Range:
            nums[mid] ... nums[high]

    ---------------------------------------------------------
    Case 2:
        nums[mid] > nums[high]

    Then:
        Left half is sorted

        Range:
            nums[low] ... nums[mid]

    ---------------------------------------------------------
    Decision Making

    Right Half Sorted:

        if(nums[mid] <= target &&
           target <= nums[high])

            search right half

        else

            search left half

    ---------------------------------------------------------
    Left Half Sorted:

        if(nums[low] <= target &&
           target <= nums[mid])

            search left half

        else

            search right half

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    In a rotated sorted array:

        One half is always sorted.

    Binary search works because
    we can safely eliminate one half
    in every iteration.

    ---------------------------------------------------------
    STL Shortcut:
        No direct STL function exists.

    Custom binary search is required.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
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

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = obj.search(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    }
    else {
        cout << "Target not found" << endl;
    }

    return 0;
}