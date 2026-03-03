/*
    Program: Maximum Subarray Sum

    Problem:
    Given an integer array, find the contiguous subarray
    with the maximum possible sum and return that sum.


    1. Brute Force Approach
       - Generate all possible subarrays.
       - Compute sum for each subarray.
       - Track the maximum sum.

       Time Complexity: O(n^3)
       Space Complexity: O(1)


    2. Better Approach
       - Fix starting index i.
       - Keep adding elements to sum for j >= i.
       - Avoid recalculating sum repeatedly.

       Time Complexity: O(n^2)
       Space Complexity: O(1)


    3. Optimal Approach (Kadane’s Algorithm)
       - Maintain running sum.
       - Add current element to sum.
       - If sum becomes negative, reset it to 0.
       - Track maximum sum seen so far.

       Time Complexity: O(n)
       Space Complexity: O(1)

       
    Important Note:
    This implementation correctly handles arrays containing
    all negative numbers because 'maxi' is initialized to INT_MIN.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(n^3)
int bruteforce(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// Better: O(n^2)
int better(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// Optimal: O(n) — Kadane's Algorithm
int optimal(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        maxi = max(maxi, sum);

        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cout << "Enter number of elements in array:\n";
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << optimal(arr);
    return 0;
}