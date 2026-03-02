/*
    Program: Find Missing Number in Array

    Problem:
    Given an array containing n distinct numbers in the range [0, n],
    find the one number that is missing.

    ---------------------------------------------------------

    1. Brute Force Approach
       - For every number from 0 to n,
         check whether it exists in the array.
       - Return the number that is not found.

       Time Complexity: O(n^2)
       Space Complexity: O(1)

    ---------------------------------------------------------

    2. Better Approach (Hashing)
       - Create a hash array of size n+1.
       - Mark visited numbers.
       - The index that remains 0 is the missing number.

       Time Complexity: O(n)
       Space Complexity: O(n)

    ---------------------------------------------------------

    3. Optimal Approach (XOR Method)
       - XOR all numbers from 0 to n.
       - XOR all elements of the array.
       - XOR of both results gives missing number.

       Time Complexity: O(n)
       Space Complexity: O(1)

    ---------------------------------------------------------

    Assumption:
    - Array contains distinct numbers.
    - Values are in range [0, n].
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
int miss(int arr[], int n){
    for(int i = 0; i <= n; i++){
        bool found = false;
        for(int j = 0; j < n; j++){
            if(i == arr[j]){
                found = true;
                break;
            }
        }
        if(found == false){
            return i;
        }
    }
    return -1;
}

// Better (Hashing)
int miss1(int arr[], int n){
    vector<int> hash(n+1, 0);

    for(int i = 0; i < n; i++){
        hash[arr[i]] = 1;
    }

    for(int i = 0; i <= n; i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return -1;
}

// Optimal (XOR)
int missingNumber(vector<int>& nums){
    int xor1 = 0, xor2 = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        xor2 ^= nums[i];
        xor1 ^= i;
    }

    xor1 ^= n;

    return xor1 ^ xor2;
}