/*
====================================================
README : Count Good Numbers (LeetCode 1922)
====================================================

Problem:
Given a number n, each position of a digit string has restrictions:
- Even indices (0,2,4...) can contain only {0,2,4,6,8} -> 5 choices.
- Odd indices (1,3,5...) can contain only prime digits {2,3,5,7} -> 4 choices.

Return the total number of valid strings modulo 1e9+7.

----------------------------------------------------
Approach 1 : Brute Force
----------------------------------------------------
Idea:
1. Count even positions = (n + 1) / 2.
2. Count odd positions = n / 2.
3. Compute:
      5^(even positions)
      4^(odd positions)
   using simple repeated multiplication.
4. Multiply both answers modulo 1e9+7.

Time Complexity : O(n)
Space Complexity: O(1)

----------------------------------------------------
Approach 2 : Optimal (Binary Exponentiation)
----------------------------------------------------
Idea:
Instead of multiplying base repeatedly, calculate powers using
Binary Exponentiation.

Observation:
5^(even positions) × 4^(odd positions)

Binary exponentiation works as:
- If exponent is odd:
      result *= base
      exponent--
- Otherwise:
      base *= base
      exponent /= 2

This reduces the number of multiplications from O(n)
to O(log n).

Time Complexity : O(log n)
Space Complexity: O(1)

----------------------------------------------------
Why Binary Exponentiation?
----------------------------------------------------
Normal Power:
2^1000000000
requires one billion multiplications.

Binary Exponentiation:
Keeps squaring the base while halving the exponent,
requiring only about log2(1e9) ≈ 30 iterations.

----------------------------------------------------
Example
----------------------------------------------------
n = 4

Even positions = 2
Odd positions = 2

Answer =
5^2 × 4^2
= 25 × 16
= 400

----------------------------------------------------
Key Learning
----------------------------------------------------
• Count positions independently.
• Apply modular arithmetic after every multiplication.
• Binary Exponentiation is the standard technique for
  computing large powers efficiently.
• Always use long long to avoid overflow before taking modulo.
====================================================

*/

class Solution {
public:

    long long mod = 1000000007LL;

    //====================================================
    // Brute Force
    // Time: O(n)
    // Space: O(1)
    //====================================================

    long long powerBrute(long long base, long long exp) {

        long long ans = 1;

        for (long long i = 0; i < exp; i++) {
            ans = (ans * base) % mod;
        }

        return ans;
    }

    int countGoodNumbersBrute(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (powerBrute(5, even) * powerBrute(4, odd)) % mod;
    }

    //====================================================
    // Optimal (Binary Exponentiation)
    // Time: O(log n)
    // Space: O(1)
    //====================================================

    long long power(long long a, long long b) {

        long long res = 1;

        while (b > 0) {

            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};