/*
    Problem: Valid Perfect Square

    Practice Link:
    https://leetcode.com/problems/valid-perfect-square/

    Pattern Used:
    Binary Search on Answer

    Goal:
    Given a positive integer num,
    determine whether it is a perfect square.

    A perfect square is a number that can be written as:

        x * x = num

    for some integer x.

    Example:

    Input:
        num = 16

    Output:
        true

    ---------------------------------------------------------
    1. Brute Force Approach

    Idea:
    Check every possible number whose square
    is less than or equal to num.

    Steps:

    1. Start from i = 1
    2. Compute i * i
    3. If i * i == num:
            return true
    4. Continue until i * i > num

    ---------------------------------------------------------
    Time Complexity:
        O(√n)

    Space Complexity:
        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    We need to find whether there exists
    an integer x such that:

        x² = num

    Instead of checking all values,
    binary search the answer.

    Search Space:

        [1 ... num]

    ---------------------------------------------------------
    Observation

    If:

        mid² <= num

    Then:

        mid can be a possible answer.

        Store mid and search right half.

    ---------------------------------------------------------

    If:

        mid² > num

    Then:

        mid is too large.

        Search left half.

    ---------------------------------------------------------
    Algorithm

    1. Initialize:
            low = 1
            high = num

    2. Compute mid

    3. Calculate:

            midSquare = mid * mid

    4. Update search space

    5. Store largest value whose square
       does not exceed num

    6. Finally check:

            ans * ans == num

    ---------------------------------------------------------
    Why long long?

    For large values:

        46341 * 46341

    exceeds int range.

    Therefore:

        mid
        midSquare

    should be stored as long long.

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are not searching for an element.

    We are searching for a value whose square
    satisfies a condition.

    This is a classic:

        Binary Search on Answer

    problem.

    ---------------------------------------------------------
    STL Shortcut

    Alternative:

        sqrt(num)

    Example:

        int root = sqrt(num);

        return root * root == num;

    However,
    interviewers usually expect the
    binary search solution.
*/

#include <iostream>
using namespace std;

class Solution {
public:

    // Brute Force Approach
    bool isPerfectSquareBrute(int num) {

        for (long long i = 1; i * i <= num; i++) {
            if (i * i == num) {
                return true;
            }
        }

        return false;
    }

    // Optimal Binary Search Approach
    bool isPerfectSquareOptimal(int num) {

        long long low = 1;
        long long high = num;
        long long ans = 1;

        while (low <= high) {

            long long mid = low + (high - low) / 2;
            long long midSquare = mid * mid;

            if (midSquare <= num) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return (ans * ans == num);
    }
};

int main() {

    Solution obj;

    int num = 16;

    cout << "Brute Force : "
         << (obj.isPerfectSquareBrute(num) ? "true" : "false")
         << endl;

    cout << "Binary Search : "
         << (obj.isPerfectSquareOptimal(num) ? "true" : "false")
         << endl;

    return 0;
}