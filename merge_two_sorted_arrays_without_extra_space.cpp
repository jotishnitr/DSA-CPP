/*
    Program: Merge Two Sorted Arrays

    Problem:
    Given two sorted arrays nums1 and nums2 of sizes m and n,
    merge nums2 into nums1 as one sorted array.

    nums1 has enough space (size = m + n) to hold extra elements.

    1. Brute Force Approach

    Idea:
    - Use an extra array to merge both arrays.
    - Then copy the merged result back into nums1.

    Steps:
    1. Use two pointers for nums1 and nums2.
    2. Compare elements and fill a new array.
    3. Copy the merged array into nums1.

    Time Complexity: O(m + n)
    Space Complexity: O(m + n)

    2. Optimal Approach (Gap Method)

    Idea:
    - Treat nums1 and nums2 as a single virtual array.
    - Compare elements at a fixed "gap" distance.
    - Reduce the gap gradually (Shell Sort idea).

    Steps:
    1. Initialize gap = ceil((m + n) / 2)
    2. Compare elements at positions (left, right)
       where right = left + gap

    3. Three cases:
        a) Both pointers in nums1
        b) One in nums1, one in nums2
        c) Both in nums2

    4. Swap elements if they are out of order.

    5. Reduce gap:
        gap = ceil(gap / 2)

    6. Repeat until gap becomes 1

    7. Finally copy nums2 into remaining part of nums1

    Time Complexity:
        O((m + n) log(m + n))

    Space Complexity:
        O(1)

    Concepts Used:
    - Two pointer comparison
    - Shell sort gap technique
    - In-place merging

    Note:
    This approach modifies both arrays during processing,
    and finally places all elements back into nums1.
*/

#include <bits/stdc++.h>
using namespace std;

// ----------- BRUTE FORCE -----------
void bruteForce(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result(m + n);

    int left = 0, right = 0, index = 0;

    // Merge both arrays
    while (left < m && right < n) {
        if (nums1[left] <= nums2[right]) {
            result[index++] = nums1[left++];
        } else {
            result[index++] = nums2[right++];
        }
    }

    // Remaining elements
    while (left < m) {
        result[index++] = nums1[left++];
    }

    while (right < n) {
        result[index++] = nums2[right++];
    }

    // Copy back to nums1 (LeetCode style)
    for (int i = 0; i < m + n; i++) {
        nums1[i] = result[i];
    }
}

// ----------- OPTIMAL (GAP METHOD) -----------
void optimal(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = m + n;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < len) {

            // Case 1: nums1 & nums2
            if (left < m && right >= m) {
                if (nums1[left] > nums2[right - m]) {
                    swap(nums1[left], nums2[right - m]);
                }
            }
            // Case 2: both in nums2
            else if (left >= m) {
                if (nums2[left - m] > nums2[right - m]) {
                    swap(nums2[left - m], nums2[right - m]);
                }
            }
            // Case 3: both in nums1
            else {
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
            }

            left++;
            right++;
        }

        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
    for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
    }
}

// ----------- MAIN FUNCTION -----------
int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};

    int m = 3, n = 3;

    // Choose which method to test:

    // bruteForce(nums1, m, nums2, n);
    optimal(nums1, m, nums2, n);

    // Print result
    cout << "Merged array: ";
    for (int x : nums1) {
        cout << x << " ";
    }

    return 0;
}