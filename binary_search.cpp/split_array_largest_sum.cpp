/*
------------------------------------------------------------
Problem: Split Array Largest Sum
Link: https://leetcode.com/problems/split-array-largest-sum/

Pattern Used:
Binary Search on Answer

Intuition:
We need to minimize the largest subarray sum after
splitting the array into exactly k subarrays.

Search Space:
low  = largest element in the array
high = sum of all elements

Why?
- Largest subarray sum can never be smaller than the
  largest element.
- Largest subarray sum can never exceed the total sum.

Validation Function:
fun(arr, maxSum)

Returns the number of subarrays required if the maximum
allowed subarray sum is maxSum.

Logic:
If currentSum + arr[i] > maxSum
→ Start a new subarray.

Binary Search:
If requiredSubarrays <= k
→ maxSum is a valid answer
→ Try smaller answer
→ high = mid - 1

Else
→ maxSum is too small
→ Increase answer
→ low = mid + 1

Key Observation:
If a maximum sum works,
all larger sums will also work.

This monotonic behaviour allows Binary Search.

Time Complexity:
O(n * log(sum))

Space Complexity:
O(1)

Similar Problems:
1. Book Allocation Problem
2. Allocate Minimum Number of Pages
3. Painter's Partition Problem
4. Capacity To Ship Packages Within D Days
------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int fun(vector<int>& arr, int maxSum) {

        int subarrays = 1;
        int currentSum = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (currentSum + arr[i] > maxSum) {
                subarrays++;
                currentSum = arr[i];
            }
            else {
                currentSum += arr[i];
            }
        }

        return subarrays;
    }

    vector<int> maxiSum(vector<int>& arr) {

        int largest = INT_MIN;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            largest = max(largest, arr[i]);
            sum += arr[i];
        }

        return {largest, sum};
    }

    // Brute Force Approach
    int splitArrayBrute(vector<int>& nums, int k) {

        vector<int> info = maxiSum(nums);

        int largest = info[0];
        int totalSum = info[1];

        for (int maxSum = largest; maxSum <= totalSum; maxSum++) {

            if (fun(nums, maxSum) <= k) {
                return maxSum;
            }
        }

        return -1;
    }

    // Optimal Binary Search Approach
    int splitArrayOptimal(vector<int>& nums, int k) {

        vector<int> info = maxiSum(nums);

        int low = info[0];
        int high = info[1];

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (fun(nums, mid) <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << "Brute Force Answer  : "
         << obj.splitArrayBrute(nums, k)
         << endl;

    cout << "Binary Search Answer: "
         << obj.splitArrayOptimal(nums, k)
         << endl;

    return 0;
}