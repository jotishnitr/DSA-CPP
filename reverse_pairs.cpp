/*
    Program: Reverse Pairs

    Problem:
    Given an array nums, count the number of reverse pairs.

    A reverse pair is defined as:
        i < j AND nums[i] > 2 * nums[j]

    Example:
    Input:  [1, 3, 2, 3, 1]
    Output: 2

    Reverse pairs:
    (3,1), (3,1)

    ---------------------------------------------------------
    1. Brute Force Approach

    Idea:
    Check all pairs (i, j) where i < j.

    Steps:
    - Use two nested loops
    - Count whenever nums[i] > 2 * nums[j]

    Time Complexity: O(n^2)
    Space Complexity: O(1)

    ---------------------------------------------------------
    2. Optimal Approach (Merge Sort)

    Key Idea:
    While merging two sorted halves, count valid pairs
    across the halves.

    Observation:
    If left half and right half are sorted,
    we can efficiently count pairs using two pointers.

    ---------------------------------------------------------
    Counting Logic:

    For each i in left half:
        Move pointer 'right' in right half such that:
            nums[i] > 2 * nums[right]

    Count += (number of valid right elements)

    ---------------------------------------------------------
    Steps:

    1. Divide array into two halves
    2. Recursively count pairs in both halves
    3. Count cross pairs using countPairs()
    4. Merge the two sorted halves

    ---------------------------------------------------------
    Time Complexity: O(n log n)
    Space Complexity: O(n)

    ---------------------------------------------------------
    Important:
    - Use long long (2LL * nums[j]) to avoid overflow
    - Counting must be done BEFORE merging
*/


#include <bits/stdc++.h>
using namespace std;

// -------------------- BRUTE FORCE --------------------
int reversePairsBrute(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > 2LL * nums[j]) {
                count++;
            }
        }
    }
    return count;
}

// -------------------- MERGE FUNCTION --------------------
void merge(vector<int>& nums, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        } else {
            temp.push_back(nums[right++]);
        }
    }

    while (left <= mid) temp.push_back(nums[left++]);
    while (right <= high) temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

// -------------------- COUNT PAIRS --------------------
int countPairs(vector<int>& nums, int low, int mid, int high) {
    int count = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high && nums[i] > 2LL * nums[right]) {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}

// -------------------- MERGE SORT --------------------
int mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return 0;

    int mid = low + (high - low) / 2;
    int count = 0;

    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);

    return count;
}

// -------------------- OPTIMAL FUNCTION --------------------
int reversePairsOptimal(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    vector<int> nums = {1, 3, 2, 3, 1};

    // Copy for brute force
    vector<int> numsCopy = nums;

    int bruteAns = reversePairsBrute(numsCopy);
    int optimalAns = reversePairsOptimal(nums);

    cout << "Brute Force Answer: " << bruteAns << endl;
    cout << "Optimal Answer: " << optimalAns << endl;

    return 0;
}
