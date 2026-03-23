/*
    Program: Maximum Product Subarray

    Problem:
    Given an integer array nums, find the contiguous subarray
    within the array that has the largest product.

    Example:
    Input:  [2, 3, -2, 4]
    Output: 6
    Explanation: Subarray [2,3] gives maximum product.

    ---------------------------------------------------------
    1. Brute Force Approach (3 Loops)

    Idea:
    Generate all subarrays and compute their product.

    Steps:
    - Fix start index i
    - Fix end index j
    - Compute product from i to j using third loop

    Time Complexity: O(n^3)
    Space Complexity: O(1)

    ---------------------------------------------------------
    2. Better Approach (2 Loops)

    Idea:
    Avoid recomputation of product.

    Steps:
    - Fix start index i
    - Maintain running product while expanding j

    Time Complexity: O(n^2)
    Space Complexity: O(1)

    ---------------------------------------------------------
    3. Optimal Approach (Prefix + Suffix Traversal)

    Key Idea:
    - Negative numbers can flip sign
    - Zero breaks subarray

    So:
    - Traverse from left → prefix product
    - Traverse from right → suffix product

    Why both?
    Because:
    - A negative product from left may become positive
      when viewed from the right side

    Steps:
    1. Maintain prefix and suffix products
    2. Reset to 1 when product becomes 0
    3. Track maximum of both

    ---------------------------------------------------------
    Time Complexity: O(n)
    Space Complexity: O(1)

    ---------------------------------------------------------
    Important:
    - Handle zeros by resetting product
    - Consider both directions due to negative values
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- BRUTE FORCE (3 LOOPS) --------------------
int maxProductBrute(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int prod = 1;

            // recompute product every time
            for (int k = i; k <= j; k++) {
                prod *= nums[k];
            }

            maxi = max(maxi, prod);
        }
    }
    return maxi;
}

// -------------------- BETTER (2 LOOPS) --------------------
int maxProductBetter(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        int prod = 1;

        for (int j = i; j < n; j++) {
            prod *= nums[j];   // reuse previous product
            maxi = max(maxi, prod);
        }
    }
    return maxi;
}

// -------------------- OPTIMAL (1 LOOP) --------------------
int maxProductOptimal(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1, suffix = 1;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}

// -------------------- MAIN --------------------
int main() {
    vector<int> nums = {2, 3, -2, 4};

    cout << "Brute Force (O(n^3)): " << maxProductBrute(nums) << endl;
    cout << "Better (O(n^2)): " << maxProductBetter(nums) << endl;
    cout << "Optimal (O(n)): " << maxProductOptimal(nums) << endl;

    return 0;
}