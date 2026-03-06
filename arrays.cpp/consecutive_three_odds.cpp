/*
    Program: Check Three Consecutive Odd Numbers

    Problem:
    Given an integer array, determine whether there exist
    three consecutive odd numbers.

    Example:
    Input: 2 3 5 7 4
    Output: true
    Explanation: 3,5,7 are three consecutive odd numbers.


    1. Brute Force Approach

    Idea:
    Check every triplet (i-1, i, i+1).

    Steps:
    - Traverse from index 1 to n-2
    - Check if arr[i-1], arr[i], arr[i+1] are all odd

    Time Complexity: O(n)
    Space Complexity: O(1)


    2. Optimal Approach

    Idea:
    Track the count of consecutive odd numbers.

    Steps:
    - Traverse array
    - If element is odd → increment count
    - If element is even → reset count
    - If count reaches 3 → return true

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// Brute force
bool bruteforce(vector<int> arr){
    int n = arr.size();

    for(int i = 1; i < n-1; i++){
        if(arr[i]%2 != 0 && arr[i-1]%2 != 0 && arr[i+1]%2 != 0){
            return true;
        }
    }

    return false;
}

// Optimal
bool optimal(vector<int>& arr){
    int count = 0;

    for(int num : arr){
        if(num % 2 != 0){
            count++;
            if(count == 3) return true;
        }
        else{
            count = 0;
        }
    }

    return false;
}

int main(){
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(optimal(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}