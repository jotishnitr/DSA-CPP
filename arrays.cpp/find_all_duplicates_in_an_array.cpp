/*
------------------------------------------------------------
Problem: Find All Duplicates in an Array
Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

Pattern Used:
Index Marking (Negative Marking)

Prerequisite:
1. Array size = n
2. Elements are in the range [1, n]
3. Each element appears either once or twice.

------------------------------------------------------------
Brute Force Approach

Idea:
For every element:
- Count its frequency by traversing the entire array.
- If frequency is 2 and it has not been added before,
  add it to the answer.

Time Complexity:
O(n²)

Space Complexity:
O(1)
(Excluding output array)

------------------------------------------------------------
Optimal Approach

Idea:
Since every number lies in the range [1, n],

Every value can be mapped to an index:

Index = abs(nums[i]) - 1

If the value at that index is positive,
mark it as visited by making it negative.

If it is already negative,
the current number has been seen before,
so it is a duplicate.

------------------------------------------------------------
Algorithm

For every element:

idx = abs(nums[i]) - 1

If nums[idx] < 0
→ Duplicate found.
→ Store idx + 1.

Else
→ Mark it as visited.

nums[idx] = -nums[idx]

------------------------------------------------------------
Dry Run

nums = [4,3,2,7,8,2,3,1]

4 -> Index 3
Mark nums[3] negative.

3 -> Index 2
Mark nums[2] negative.

2 -> Index 1
Mark nums[1] negative.

7 -> Index 6
Mark nums[6] negative.

8 -> Index 7
Mark nums[7] negative.

2 -> Index 1
Already negative
Duplicate = 2

3 -> Index 2
Already negative
Duplicate = 3

Answer = [2,3]

------------------------------------------------------------
Key Observation

Since every value belongs to [1, n],

each value has a unique corresponding index.

Negative marking allows us to record whether
an element has been visited without using
any extra space.

------------------------------------------------------------
Time Complexity

Brute Force:
O(n²)

Optimal:
O(n)

------------------------------------------------------------
Space Complexity

Brute Force:
O(1)
(Excluding output array)

Optimal:
O(1)
(Excluding output array)

------------------------------------------------------------
Similar Problems

1. Find the Duplicate Number
2. Find All Numbers Disappeared in an Array
3. First Missing Positive
4. Set Mismatch
5. Cyclic Sort Problems
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:

    // Brute Force Approach
    vector<int> findDuplicatesBrute(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count == 2) {

                bool alreadyAdded = false;

                for (int x : ans) {
                    if (x == nums[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }

                if (!alreadyAdded) {
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }

    // Optimal Approach (Negative Marking)
    vector<int> findDuplicatesOptimal(vector<int>& nums) {

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                ans.push_back(idx + 1);
            }
            else {
                nums[idx] = -nums[idx];
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums2 = nums1;   // Copy because optimal modifies the array

    vector<int> brute = obj.findDuplicatesBrute(nums1);
    vector<int> optimal = obj.findDuplicatesOptimal(nums2);

    cout << "Brute Force Duplicates: ";
    for (int x : brute) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Optimal Duplicates    : ";
    for (int x : optimal) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}