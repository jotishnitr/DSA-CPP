/*
  
Problem: Left Rotate Array by K Places
Category: Arrays
Difficulty: Easy

Problem Statement:
Given an array of size N, rotate the array to the left
by K positions.

Example:
Input: [1 2 3 4 5], K = 2
Output: [3 4 5 1 2]

Approach : Optimal (Reversal Algorithm)
Steps:
1. Reverse first K elements.
2. Reverse remaining N-K elements.
3. Reverse entire array.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int d;
    cin>>d;
    reverse(array,array+d);
    reverse(array+d,array+n);
    reverse(array,array+n);
    for(int i=0;i<n;i++){
        cout<<array[i]<<endl;
    }
    return 0;
}


