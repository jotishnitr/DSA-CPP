/*
    Program: Next Permutation

    Problem:
    Given an array representing a permutation of numbers,
    rearrange it into the next lexicographically greater permutation.
    If such arrangement is not possible, rearrange it into
    the lowest possible order (ascending).

    Example:
    Input: 1 2 3
    Output: 1 3 2

    Input: 3 2 1
    Output: 1 2 3


    Better Approach (Using STL)
    - Use the built-in function next_permutation().
    - It automatically generates the next lexicographic permutation.

    Time Complexity: O(n)
    Space Complexity: O(1)


    Optimal Approach (Manual Algorithm)

    Step 1: Find the "break point"
        Traverse from right.
        Find the first index i such that:
            nums[i] < nums[i+1]

    Step 2: If no such index exists
        The array is the last permutation.
        Reverse the entire array to get the first permutation.

    Step 3: Find the next greater element
        From the right side, find the first element
        greater than nums[index].

    Step 4: Swap them.

    Step 5: Reverse the suffix
        Reverse the portion after index to get the
        next smallest lexicographic arrangement.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void better(vector<int>& nums){
    next_permutation(nums.begin(), nums.end());
}

void optimal(vector<int>& nums){
    int n = nums.size();
    int index = -1;

    // Step 1: Find breakpoint
    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }

    // Step 2: If last permutation
    if(index == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find next greater element
    for(int i = n-1; i > index; i--){
        if(nums[i] > nums[index]){
            swap(nums[i], nums[index]);
            break;
        }
    }

    // Step 4: Reverse suffix
    reverse(nums.begin() + index + 1, nums.end());
}

int main(){
    int n;
    cout << "Enter number of elements in array:" << endl;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    optimal(nums);

    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }

    return 0;
}