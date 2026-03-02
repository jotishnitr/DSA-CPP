/*
    Function: findMaxConsecutiveOnes

    Problem:
    Given a binary array (containing only 0s and 1s),
    return the maximum number of consecutive 1s.

    Approach:
    - Traverse the array once.
    - Maintain a counter to track current streak of 1s.
    - If element is 1 → increment count.
    - If element is 0 → reset count to 0.
    - Track the maximum streak using a variable 'maxi'.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Why This Is Optimal:
    - Single traversal.
    - No extra data structures.
    - Every element is processed exactly once.

    Edge Cases:
    - Empty array → returns 0.
    - All zeros → returns 0.
    - All ones → returns array size.
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            count++;
            maxi = max(maxi, count);
        }
        else{
            count = 0;
        }
    }

    return maxi;
}