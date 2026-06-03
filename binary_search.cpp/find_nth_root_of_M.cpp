/*
    Problem: Find Nth Root of a Number

    Practice Link:
    https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

    Pattern Used:
    Binary Search on Answer

    Goal:
    Given two integers:

        n = root
        m = number

    Find an integer x such that:

        x^n = m

    If no integer nth root exists,
    return -1.

    ---------------------------------------------------------
    Example

    Input:
        n = 3
        m = 27

    Output:
        3

    Explanation:

        3^3 = 27

    ---------------------------------------------------------

    Input:
        n = 3
        m = 28

    Output:
        -1

    Explanation:

        No integer x exists such that:

            x^3 = 28

    =========================================================
    1. Brute Force Approach

    Idea:

    Check every number from 1 to m
    and determine whether its nth power
    equals m.

    Steps:

    1. Iterate from i = 1 to m

    2. Compute:

            i^n

    3. If:

            i^n == m

       return i

    4. Otherwise continue searching

    5. If no root found:
            return -1

    ---------------------------------------------------------
    Optimization

    While computing power:

        if(value > m)

    stop immediately.

    No need to continue multiplying.

    ---------------------------------------------------------
    Time Complexity:

        O(m * n)

    Space Complexity:

        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    We need to find a value x such that:

        x^n = m

    Search Space:

        [1 ... m]

    Use binary search on the possible root.

    =========================================================
    Helper Function

        func(mid, n, m)

    Purpose:

        Compare mid^n with m

    Returns:

        0 -> mid^n < m

        1 -> mid^n == m

        2 -> mid^n > m

    ---------------------------------------------------------
    Early Exit Optimization

    While computing:

        ans *= mid

    If:

        ans > m

    immediately return:

        2

    This avoids unnecessary work and
    reduces overflow risk.

    =========================================================
    Binary Search Logic

    If:

        mid^n == m

    Then:

        nth root found.

        return mid

    ---------------------------------------------------------

    If:

        mid^n < m

    Then:

        root must be larger.

            low = mid + 1

    ---------------------------------------------------------

    If:

        mid^n > m

    Then:

        root must be smaller.

            high = mid - 1

    =========================================================
    Algorithm

    1. Search between 1 and m

    2. Compute mid

    3. Compare mid^n with m

    4. Move search space accordingly

    5. Return root if found

    6. Otherwise return -1

    =========================================================
    Time Complexity

    Binary Search:
        O(log m)

    Power Computation:
        O(n)

    Total:

        O(n * log m)

    =========================================================
    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are not searching for an element.

    We are searching for a value that satisfies:

        x^n = m

    This is a classic:

        Binary Search on Answer

    problem.

    ---------------------------------------------------------
    Why Binary Search Works

    As x increases:

        x^n

    also increases.

    Therefore the search space is monotonic,
    which makes binary search applicable.

    ---------------------------------------------------------
    STL Shortcut

    Possible:

        int root = pow(m, 1.0 / n);

    However:

        Floating-point precision errors
        may produce incorrect answers.

    Binary search is the preferred
    interview solution.
*/

#include <iostream>
using namespace std;

class Solution {
public:

    // Helper function
    int func(int mid, int n, int m) {

        long long ans = 1;

        for(int i = 1; i <= n; i++) {
            ans *= mid;

            if(ans > m) {
                return 2;
            }
        }

        if(ans < m) return 0;

        return 1;
    }

    // Brute Force Approach
    int nthRootBrute(int n, int m) {

        for(int i = 1; i <= m; i++) {

            long long val = 1;

            for(int j = 1; j <= n; j++) {
                val *= i;

                if(val > m) break;
            }

            if(val == m) {
                return i;
            }
        }

        return -1;
    }

    // Optimal Binary Search Approach
    int nthRootOptimal(int n, int m) {

        if(m == 0) return 0;

        int low = 1;
        int high = m;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int result = func(mid, n, m);

            if(result == 1) {
                return mid;
            }
            else if(result == 0) {
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

    int n = 3;
    int m = 27;

    cout << "Brute Force Answer : "
         << obj.nthRootBrute(n, m)
         << endl;

    cout << "Binary Search Answer : "
         << obj.nthRootOptimal(n, m)
         << endl;

    return 0;
}