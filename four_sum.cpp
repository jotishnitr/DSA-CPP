/*
    Program: 4Sum Problem

    Problem:
    Given an array and a target value, find all unique
    quadruplets such that:
        nums[i] + nums[j] + nums[k] + nums[l] == target


    1. Brute Force
        - 4 nested loops
        - Store sorted quadruplets in set

        Time: O(n^4)


    2. Better (Hashing)
        - Fix i, j
        - Use set to find remaining pair

        Time: O(n^3 log n)

   
    3. Optimal (Two Pointer)
        - Sort array
        - Fix i and j
        - Use two pointers k and l

        Time: O(n^3)
        Space: O(1) (excluding output)
*/

#include<bits/stdc++.h>
using namespace std;

// Optimal
vector<vector<int>> optimal(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 3; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        for(int j = i + 1; j < n - 2; j++){
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1;
            int l = n - 1;

            while(k < l){
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while(k < l && nums[k] == nums[k - 1]) k++;
                    while(k < l && nums[l] == nums[l + 1]) l--;
                }
            }
        }
    }

    return result;
}

int main(){
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = optimal(nums, target);

    for(auto &vec : ans){
        for(int x : vec){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}