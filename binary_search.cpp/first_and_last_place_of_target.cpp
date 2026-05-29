/*
    Problem: Find First and Last Position of Element in Sorted Array

    Practice Link:
    https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

    Patterns Used:
    - First True Binary Search
    - Last True Binary Search
    - Boundary Binary Search

    Goal:
    Given a sorted array nums and a target value,
    return the starting and ending position of target.

    If target does not exist,
    return {-1, -1}.

    ---------------------------------------------------------
    Example

    Input:
        nums = [5,7,7,8,8,10]
        target = 8

    Output:
        [3,4]

    ---------------------------------------------------------
    APPROACH 1:
    Using Lower Bound + Upper Bound

    Core Idea:

    Lower Bound:
        FIRST index where:
            arr[index] >= target

    Upper Bound:
        FIRST index where:
            arr[index] > target

    Then:
        first occurrence = lower bound
        last occurrence  = upper bound - 1

    ---------------------------------------------------------
    Logic

    If:
        lb == nums.size()
        OR
        nums[lb] != target

    then target does not exist.

    ---------------------------------------------------------
    STL Shortcut

    int lb =
        lower_bound(nums.begin(), nums.end(), target)
        - nums.begin();

    int ub =
        upper_bound(nums.begin(), nums.end(), target)
        - nums.begin();

    Final Answer:
        {lb, ub - 1}

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    =========================================================
    APPROACH 2:
    Explicit First Occurrence + Last Occurrence

    ---------------------------------------------------------
    First Occurrence

    Find:
        FIRST position where arr[mid] == target

    Logic:
        if target found:
            store answer
            continue searching LEFT

    Because earlier occurrence may exist.

    ---------------------------------------------------------
    Last Occurrence

    Find:
        LAST position where arr[mid] == target

    Logic:
        if target found:
            store answer
            continue searching RIGHT

    Because later occurrence may exist.

    ---------------------------------------------------------
    Key Difference

    First Occurrence:
        high = mid - 1

    Last Occurrence:
        low = mid + 1

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    Binary Search is not only about finding target.

    Most advanced problems are:
        finding boundaries
        finding first valid index
        finding last valid index
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // =====================================================
    // APPROACH 1 : Lower Bound + Upper Bound
    // =====================================================

    int lowerBound(const vector<int>& arr, int target) {
        int low = 0;
        int high = static_cast<int>(arr.size()) - 1;
        int ans = arr.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(const vector<int>& arr, int target) {
        int low = 0;
        int high = static_cast<int>(arr.size()) - 1;
        int ans = arr.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int lb = lowerBound(nums, target);

        if (lb == n || nums[lb] != target) {
            return {-1, -1};
        }

        int ub = upperBound(nums, target);

        return {lb, ub - 1};
    }

    // =====================================================
    // APPROACH 2 : First Occurrence + Last Occurrence
    // =====================================================

    int firstOccurrence(const vector<int>& arr, int target) {
        int low = 0;
        int high = static_cast<int>(arr.size()) - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int lastOccurrence(const vector<int>& arr, int target) {
        int low = 0;
        int high = static_cast<int>(arr.size()) - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRangeApproach2(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);

        if (first == -1) {
            return {-1, -1};
        }

        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};

// =====================================================
// VS Code Testing
// =====================================================

int main() {
    Solution obj;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = obj.searchRange(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
