/*
    Program: 3Sum Problem

    Problem:
    Given an array of integers, find all unique triplets
    (i, j, k) such that:
        nums[i] + nums[j] + nums[k] == 0

    The solution set must not contain duplicate triplets.

    Example:
    Input:  -1 0 1 2 -1 -4
    Output: [-1, -1, 2], [-1, 0, 1]

    1. Brute Force Approach

    Idea:
    Try all possible triplets using three nested loops.

    Steps:
    - Fix i, j, k
    - Check if sum == 0
    - Sort triplet before inserting into set to avoid duplicates

    Time Complexity: O(n^3)
    Space Complexity: O(no. of unique triplets)

    2. Better Approach (Hashing)

    Idea:
    Fix one element and use a hash set to find the third element.

    Steps:
    - Fix i
    - For each j, compute:
          third = -(nums[i] + nums[j])
    - Check if third exists in set

    Time Complexity: O(n^2 log n)
    Space Complexity: O(n)

    Note:
    Set is still used to remove duplicate triplets.

    3. Optimal Approach (Two Pointer Technique)

    Key Idea:
    - Sort the array
    - Use two pointers to find pairs

    Steps:
    1. Sort array
    2. Fix i
    3. Use two pointers:
         j = i+1, k = n-1
    4. If sum < 0 → move j forward
       If sum > 0 → move k backward
       If sum == 0 → store triplet
    5. Skip duplicates for i, j, k

    Time Complexity: O(n^2)
    Space Complexity: O(1) (excluding output)

    Important Concepts:
    - Sorting enables two-pointer technique
    - Duplicate handling is critical
    - Using long long avoids overflow
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteForce(vector<int> nums){
    set<vector<int>> st;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // important
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}


vector<vector<int>> better(vector<int> nums){
    set<vector<int>> st;

    for(int i = 0; i < nums.size(); i++){
        set<int> hash_set;

        for(int j = i + 1; j < nums.size(); j++){
            int third = -(nums[i] + nums[j]);

            if(hash_set.find(third) != hash_set.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end()); // important
                st.insert(temp);
            }

            hash_set.insert(nums[j]);
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}


vector<vector<int>> optimal(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;
        int k = nums.size() - 1;

        while(j < k){
            long long sum = (long long)nums[i] + nums[j] + nums[k];

            if(sum > 0) k--;
            else if(sum < 0) j++;
            else{
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }

    return result;
}


int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = optimal(nums);

    for(auto &vec : ans){
        for(int x : vec){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}