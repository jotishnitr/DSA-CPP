/*
    Program: Count Inversions in an Array

    Problem:
    Given an array, count the number of inversions.

    An inversion is defined as:
        i < j AND arr[i] > arr[j]

    Example:
    Input:  [5, 3, 2, 4, 1]
    Output: 8

    Inversions:
    (5,3), (5,2), (5,4), (5,1),
    (3,2), (3,1),
    (2,1),
    (4,1)

    ---------------------------------------------------------
    1. Brute Force Approach

    Idea:
    Check all pairs (i, j) where i < j.

    Steps:
    - Use two nested loops
    - Count whenever arr[i] > arr[j]

    Time Complexity: O(n^2)
    Space Complexity: O(1)

    ---------------------------------------------------------
    2. Optimal Approach (Merge Sort)

    Key Idea:
    While merging two sorted halves, we can count
    how many elements from the left half are greater
    than elements in the right half.

    Observation:
    If arr[left] > arr[right],
    then all elements from left to mid are greater.

    Count += (mid - left + 1)

    ---------------------------------------------------------
    Steps:

    1. Divide array into two halves
    2. Recursively count inversions in both halves
    3. Count cross inversions during merge

    ---------------------------------------------------------
    Time Complexity: O(n log n)
    Space Complexity: O(n)

    ---------------------------------------------------------
    Concepts Used:
    - Divide and Conquer
    - Merge Sort
    - Counting during merge
*/

#include <bits/stdc++.h>
using namespace std;

int bruteforce(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergesort(vector<int>& arr, int low, int high) {
    int count = 0;
    if (low >= high) return 0;

    int mid = (low + high) / 2;
    count += mergesort(arr, low, mid);
    count += mergesort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};

    cout << "Brute force inversions: " << bruteforce(arr) << endl;

    vector<int> arr2 = arr; // copy for merge sort
    cout << "Merge sort inversions: " << mergesort(arr2, 0, arr2.size() - 1) << endl;

    return 0;
}