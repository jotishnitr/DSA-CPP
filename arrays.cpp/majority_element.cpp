/*
    Program: Majority Element (Element appearing more than n/2 times)

    Problem:
    Given an array of size n, find the element that appears
    more than n/2 times. If no such element exists, return -1.

    ---------------------------------------------------------

    1. Brute Force Approach
       - For every element, count its occurrences.
       - If count > n/2, return that element.

       Time Complexity: O(n^2)
       Space Complexity: O(1)

    ---------------------------------------------------------

    2. Better Approach (Hashing)
       - Use unordered_map to store frequency.
       - Traverse map and check if any frequency > n/2.

       Time Complexity: O(n)
       Space Complexity: O(n)

    ---------------------------------------------------------

    3. Optimal Approach (Moore’s Voting Algorithm)
       - Maintain a candidate and count.
       - Increase count if same element.
       - Decrease count if different element.
       - After first pass, verify the candidate.

       Time Complexity: O(n)
       Space Complexity: O(1)

    ---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
int bruteforce(vector<int>& arr){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        int count = 0;

        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        if(count > n/2){
            return arr[i];
        }
    }

    return -1;
}

// Better (Hashing)
int better(vector<int>& arr){
    int n = arr.size();
    unordered_map<int,int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        if(it.second > n/2){
            return it.first;
        }
    }

    return -1;
}

// Optimal (Moore's Voting Algorithm)
int optimal(vector<int>& arr){
    int n = arr.size();
    int count = 0;
    int candidate = -1;

    // Step 1: Find potential candidate
    for(int i = 0; i < n; i++){
        if(count == 0){
            candidate = arr[i];
            count = 1;
        }
        else if(arr[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    // Step 2: Verify candidate
    count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == candidate){
            count++;
        }
    }

    if(count > n/2){
        return candidate;
    }

    return -1;
}

int main(){
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << optimal(arr);

    return 0;
}