/*
    Program: Two Sum Problem

    Problem:
    Given an array of integers and a target value,
    find two indices such that their sum equals target.
    If no such pair exists, return {-1, -1}.


    1. Brute Force Approach
       - Check every pair (i, j).
       - If array[i] + array[j] == target → return indices.

       Time Complexity: O(n^2)
       Space Complexity: O(1)


    2. Better Approach (Hash Map)
       - Store elements and their indices in a map.
       - For each element, check if (target - element)
         already exists in the map.

       Time Complexity: O(n)
       Space Complexity: O(n)

       This is the optimal solution if indices are required.


    3. Two Pointer Approach (After Sorting)
       - Sort array.
       - Use left and right pointers.
       - Move pointers based on sum comparison.

       Time Complexity: O(n log n) due to sorting
       Space Complexity: O(1)

       Note:
       This approach only works if you only need
       to check existence of a pair.
       It does NOT preserve original indices.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> bruteforce(int n, vector<int> array, int target){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(array[i] + array[j] == target){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Better (Hash Map) — TRUE optimal for index return
vector<int> better(int n, vector<int> array, int target){
    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++){
        int rem = target - array[i];

        if(mp.find(rem) != mp.end()){
            return {mp[rem], i};
        }

        mp[array[i]] = i;
    }

    return {-1, -1};
}

// Two Pointer (only for existence check)
string twoPointer(int n, vector<int> array, int target){
    sort(array.begin(), array.end());

    int left = 0, right = n - 1;

    while(left < right){
        int sum = array[left] + array[right];

        if(sum == target) return "yes";
        else if(sum < target) left++;
        else right--;
    }

    return "no";
}

int main(){
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> array(n);

    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    vector<int> ans = better(n, array, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}