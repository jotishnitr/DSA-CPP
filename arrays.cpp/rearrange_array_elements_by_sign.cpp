/*
    Program: Rearrange Array by Sign

    Problem:
    Given an array with equal number of positive and negative numbers,
    rearrange it so that positives and negatives alternate.

    Example:
    Input:  [3, -2, 1, -5, 2, -4]
    Output: [3, -2, 1, -5, 2, -4]


    1. Brute Force Approach
       - Store positives in one array.
       - Store negatives in another array.
       - Merge them alternately.

       Time Complexity: O(n)
       Space Complexity: O(n)


    2. Optimal Approach
       - Create result array of size n.
       - Maintain two pointers:
            positive index = 0
            negative index = 1
       - Place positives at even indices.
       - Place negatives at odd indices.

       Time Complexity: O(n)
       Space Complexity: O(n)

    Assumption:
    - Number of positives == number of negatives.
*/

#include<bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> bruteforce(vector<int>& nums){
    int n = nums.size();

    vector<int> positives;
    vector<int> negatives;

    for(int i = 0; i < n; i++){
        if(nums[i] > 0)
            positives.push_back(nums[i]);
        else
            negatives.push_back(nums[i]);
    }

    for(int i = 0; i < n/2; i++){
        nums[2*i] = positives[i];
        nums[2*i + 1] = negatives[i];
    }

    return nums;
}

// Optimal
vector<int> optimal(vector<int>& nums){
    int n = nums.size();
    vector<int> result(n);

    int posIndex = 0;
    int negIndex = 1;

    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            result[posIndex] = nums[i];
            posIndex += 2;
        }
        else{
            result[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return result;
}

int main(){
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> result = optimal(nums);

    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }

    return 0;
}