/*

Problem: Sort an Array of 0s, 1s, and 2s
Category: Arrays / Dutch National Flag Algorithm
Difficulty: Medium

Problem Statement:
Given an array consisting only of 0s, 1s, and 2s,
sort the array in ascending order without using
a built-in sorting function.

Example:
Input:  [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]

Approach 1: Brute Force (Sorting)
- Use built-in sort() or any sorting algorithm.
- Time Complexity: O(n log n)
- Space Complexity: O(1)

Not optimal because we are solving a special case problem.

Approach 2: Better (Counting Method)
- Count number of 0s, 1s, and 2s.
- Overwrite array using counts.

Algorithm:
1. Traverse once and count frequency.
2. Rewrite array in sorted order.

Time Complexity: O(n)
Space Complexity: O(1)


Approach 3: Optimal (Dutch National Flag Algorithm)

Idea:
Use three pointers:
- low → next position for 0
- mid → current element
- high → next position for 2

Algorithm:
1. Initialize:
   low = 0, mid = 0, high = n - 1
2. While mid <= high:
   - If arr[mid] == 0:
       swap(arr[low], arr[mid])
       low++, mid++
   - If arr[mid] == 1:
       mid++
   - If arr[mid] == 2:
       swap(arr[mid], arr[high])
       high--

Time Complexity: O(n)
Space Complexity: O(1)


Key Learning:
When the number of distinct elements is small and known,
a multi-pointer approach can solve the problem in one pass.

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> better(vector<int>&nums) {
    int n=nums.size();
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) count0++;
        else if (nums[i] == 1) count1++;
        else if (nums[i] == 2) count2++;
    }

    for (int i = 0; i < count0; i++) nums[i] = 0;
    for (int i = count0; i < count0 + count1; i++) nums[i] = 1;
    for (int i = count0 + count1; i < n; i++) nums[i] = 2;

    return nums;
}

vector<int> optimal(vector<int>& nums) {
    int low = 0, mid = 0, high = (int)nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return nums;
}

int main() {
    int n;
    cout << "Enter no. of elements in array: " << endl;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int>result=optimal(nums);
    cout << "Sorted array: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}