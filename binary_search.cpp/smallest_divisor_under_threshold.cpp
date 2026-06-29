/*
    Problem: Find the Smallest Divisor Given a Threshold

    Practice Link:
    https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

    Pattern Used:
    Binary Search on Answer

    Goal:
    Given an array nums and an integer threshold,
    find the smallest divisor such that:

        Σ ceil(nums[i] / divisor)

    is less than or equal to threshold.

    ---------------------------------------------------------
    Example

    Input:

        nums = [1,2,5,9]
        threshold = 6

    Output:

        5

    Explanation:

        divisor = 5

        ceil(1/5) = 1
        ceil(2/5) = 1
        ceil(5/5) = 1
        ceil(9/5) = 2

        Sum = 5

        5 <= 6

    Any smaller divisor produces
    a larger sum.

    =========================================================
    Observation

    As divisor increases:

        ceil(nums[i] / divisor)

    decreases or remains same.

    Therefore:

        total sum decreases.

    Example:

        divisor = 1  -> sum = large
        divisor = 2  -> smaller
        divisor = 3  -> smaller
        divisor = 4  -> smaller
        divisor = 5  -> valid

    Pattern:

        F F F F T T T

    Therefore:

        Binary Search on Answer

    can be applied.

    =========================================================
    Helper Function

        sumByDivisor(arr, divisor)

    Purpose:

        Calculate

            Σ ceil(arr[i] / divisor)

    Example:

        arr = [1,2,5,9]
        divisor = 5

        1 + 1 + 1 + 2 = 5

    ---------------------------------------------------------
    Optimization

    Instead of:

        ceil((double)a / divisor)

    Use integer arithmetic:

        (a + divisor - 1) / divisor

    Example:

        (9 + 5 - 1) / 5
        = 13 / 5
        = 2

    Avoids floating-point operations.

    =========================================================
    Helper Function

        maxEl(arr)

    Purpose:

        Find largest element.

    Why?

        Maximum useful divisor
        is the maximum array element.

    Search Space:

        [1 ... maxElement]

    =========================================================
    1. Brute Force Approach

    Idea:

    Try every divisor from:

        1 to maxElement

    First divisor satisfying:

        sum <= threshold

    is the answer.

    ---------------------------------------------------------
    Time Complexity:

        O(maxElement * n)

    Space Complexity:

        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    Search for the smallest divisor
    that satisfies:

        sumByDivisor(divisor)
            <= threshold

    ---------------------------------------------------------
    Binary Search Condition

    If:

        sumByDivisor(mid)
            <= threshold

    Then:

        mid is a valid divisor.

        Store answer and search left
        for a smaller valid divisor.

            high = mid - 1

    ---------------------------------------------------------

    If:

        sumByDivisor(mid)
            > threshold

    Then:

        divisor is too small.

        Need a larger divisor.

            low = mid + 1

    =========================================================
    Algorithm

    1. Search space:

            [1 ... maxElement]

    2. Compute mid divisor

    3. Calculate required sum

    4. Check validity

    5. Move search space

    6. Return smallest valid divisor

    =========================================================
    Time Complexity

    Binary Search:
        O(log(maxElement))

    Sum Calculation:
        O(n)

    Total:

        O(n * log(maxElement))

    =========================================================
    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are not searching for an element.

    We are searching for the smallest divisor
    that satisfies a condition.

    Condition:

        sumByDivisor(divisor)
            <= threshold

    This is a classic:

        Binary Search on Answer

    problem.

    ---------------------------------------------------------
    STL Shortcut:
        No direct STL solution exists.

    Custom binary search is required.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:

    int sumByDivisor(vector<int>& arr, int divisor) {

        int sum = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += ceil((double)arr[i] / divisor);
        }

        return sum;
    }

    int maxEl(vector<int>& arr) {

        int largest = INT_MIN;

        for(int i = 0; i < arr.size(); i++) {
            largest = max(largest, arr[i]);
        }

        return largest;
    }

    // Brute Force Approach
    int smallestDivisorBrute(vector<int>& nums, int threshold) {

        int maxi = maxEl(nums);

        for(int divisor = 1; divisor <= maxi; divisor++) {

            if(sumByDivisor(nums, divisor) <= threshold) {
                return divisor;
            }
        }

        return -1;
    }

    // Optimal Binary Search Approach
    int smallestDivisorOptimal(vector<int>& nums, int threshold) {

        int low = 1;
        int high = maxEl(nums);

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(sumByDivisor(nums, mid) <= threshold) {
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

    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Brute Force Answer : "
         << obj.smallestDivisorBrute(nums, threshold)
         << endl;

    cout << "Binary Search Answer : "
         << obj.smallestDivisorOptimal(nums, threshold)
         << endl;

    return 0;
}