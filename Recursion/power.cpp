/*
====================================================
LeetCode 50. Pow(x, n)
https://leetcode.com/problems/powx-n/

Approaches:
1. Brute Force
   - Multiply x by itself |n| times.
   - If n is negative, return 1 / answer.
   - Time Complexity: O(n)
   - Space Complexity: O(1)

2. Optimal (Binary Exponentiation / Fast Power)
   - If n is odd:
       Multiply answer by x and reduce n by 1.
   - If n is even:
       Square x and divide n by 2.
   - Continue until n becomes 0.
   - Handle negative exponents by taking reciprocal.
   - Use long long to safely handle INT_MIN.
   - Time Complexity: O(log n)
   - Space Complexity: O(1)

Concepts Used:
- Binary Exponentiation
- Exponentiation by Squaring
- Mathematical Optimization
- Handling Negative Powers
- Integer Overflow Prevention (INT_MIN)

Similar Problems:
- LeetCode 50 - Pow(x, n)
- GeeksforGeeks - Power of Numbers
  https://www.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
====================================================
*/

class Solution {
public:

    //====================================================
    // Brute Force
    // Time: O(n)
    // Space: O(1)
    //====================================================

    double myPowBrute(double x, int n) {

        long long nn = n;

        if (nn < 0)
            nn = -nn;

        double ans = 1.0;

        for (long long i = 0; i < nn; i++) {
            ans *= x;
        }

        if (n < 0)
            return 1.0 / ans;

        return ans;
    }

    //====================================================
    // Optimal (Binary Exponentiation)
    // Time: O(log n)
    // Space: O(1)
    //====================================================

    double myPow(double x, int n) {

        long long nn = n;
        double ans = 1.0;

        if (nn < 0)
            nn = -nn;

        while (nn) {

            if (nn % 2) {
                ans *= x;
                nn--;
            }
            else {
                x *= x;
                nn /= 2;
            }
        }

        if (n < 0)
            return 1.0 / ans;

        return ans;
    }
};