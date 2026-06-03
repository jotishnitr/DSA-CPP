/*
    Problem: Square Root of a Number (Floor Value)

    Practice Link:
    https://www.geeksforgeeks.org/problems/square-root/1

    Pattern Used:
    Binary Search on Answer

    Goal:
    Given a non-negative integer n,
    find the floor value of its square root.

    Floor Square Root:

        Largest integer x such that

            x * x <= n

    ---------------------------------------------------------
    Example

    Input:
        n = 28

    Output:
        5

    Explanation:

        5 * 5 = 25
        6 * 6 = 36

        25 <= 28 < 36

        Therefore floor sqrt(28) = 5

    =========================================================
    1. Brute Force Approach

    Idea:
    Check every number starting from 1
    until its square exceeds n.

    Steps:

    1. Start from i = 1
    2. While i * i <= n
    3. Update answer = i
    4. Return last valid value

    ---------------------------------------------------------
    Time Complexity:
        O(√n)

    Space Complexity:
        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    We need the largest value x satisfying:

        x² <= n

    Search Space:

        [1 ... n]

    Use binary search on possible answers.

    ---------------------------------------------------------
    Observation

    If:

        mid² <= n

    Then:

        mid is a valid answer.

        Store it and search right half
        for a larger valid answer.

    ---------------------------------------------------------

    If:

        mid² > n

    Then:

        mid is too large.

        Search left half.

    ---------------------------------------------------------
    Algorithm

    1. Initialize:
            low = 1
            high = n
            ans = 1

    2. Compute mid

    3. Calculate:

            midSquare = mid * mid

    4. If valid:
            store answer
            move right

    5. Otherwise:
            move left

    6. Return ans

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

    We are searching for the maximum value
    satisfying a condition:

        x² <= n

    This is a classic:

        Binary Search on Answer

    problem.

    ---------------------------------------------------------
    STL Shortcut

    Alternative:

        int ans = sqrt(n);

    But interview expectation is usually
    the binary search solution.
*/

#include <iostream>
using namespace std;

class Solution {
public:

    // Brute Force Approach
    int floorSqrtBrute(int n) {

        int ans = 0;

        for(long long i = 1; i * i <= n; i++) {
            ans = i;
        }

        return ans;
    }

    // Optimal Binary Search Approach
    int floorSqrtOptimal(int n) {

        if(n == 0) return 0;

        long long low = 1;
        long long high = n;
        long long ans = 1;

        while(low <= high) {

            long long mid = low + (high - low) / 2;
            long long midSquare = mid * mid;

            if(midSquare <= n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n = 28;

    cout << "Brute Force Floor Sqrt : "
         << obj.floorSqrtBrute(n) << endl;

    cout << "Binary Search Floor Sqrt : "
         << obj.floorSqrtOptimal(n) << endl;

    return 0;
}
