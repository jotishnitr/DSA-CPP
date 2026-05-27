/*
    Problem: Binary Search

    Goal:
    Given a sorted array nums and a target value,
    return the index of the target if it exists.
    Otherwise return -1.

    Example:
    Input:
        nums = [-1,0,3,5,9,12]
        target = 9

    Output:
        4

    ---------------------------------------------------------
    Core Idea

    Binary Search works only on SORTED arrays.

    Instead of searching linearly,
    repeatedly divide the search space into half.

    ---------------------------------------------------------
    Approach

    1. Maintain two pointers:
            low  -> start of search range
            high -> end of search range

    2. Compute middle index:
            mid = (low + high) / 2

    3. Compare nums[mid] with target:
        - If equal -> target found
        - If nums[mid] > target
              search left half
        - Else
              search right half

    4. Continue until low > high

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Because search space is halved every iteration.

    ---------------------------------------------------------
    Space Complexity:
        O(1)

    No extra space used.

    ---------------------------------------------------------
    Important Condition

    while(low <= high)

    '=' is important because:
    when low == high,
    one element is still left to check.

    ---------------------------------------------------------
    Binary Search Requirement:
    Array must be sorted.
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
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int result = obj.search(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}