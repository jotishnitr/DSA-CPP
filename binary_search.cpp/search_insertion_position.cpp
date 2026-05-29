/*
    Problem: Search Insert Position

    Practice Link:
    https://leetcode.com/problems/search-insert-position/

    Pattern Used:
    First True Binary Search (Lower Bound)

    Goal:
    Given a sorted array and a target value,
    return the index if the target is found.

    If not found,
    return the index where it should be inserted
    to maintain sorted order.

    ---------------------------------------------------------
    Example

    Input:
        nums = [1,3,5,6]
        target = 5

    Output:
        2

    Input:
        nums = [1,3,5,6]
        target = 2

    Output:
        1

    ---------------------------------------------------------
    Core Idea

    We need the FIRST index where:
        nums[index] >= target

    That position is:
    - the actual target index if present
    - otherwise the correct insertion position

    This is exactly the Lower Bound concept.

    ---------------------------------------------------------
    Approach

    1. Initialize:
            low = 0
            high = n - 1
            ans = n

    2. Find mid

    3. If nums[mid] >= target:
            store mid as possible answer
            search left half

    4. Else:
            search right half

    5. Return ans

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    Search Insert Position
    is simply:
        Lower Bound of target
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int result = obj.searchInsert(nums, target);

    cout << "Insert Position: " << result << endl;

    return 0;
}