/*
------------------------------------------------------------
Problem: Find the Duplicate Number
Link: https://leetcode.com/problems/find-the-duplicate-number/

Pattern Used:
Binary Search on Answer (Pigeonhole Principle)

Prerequisite:
1. Array size = n + 1
2. Elements are in the range [1, n]
3. Exactly one number is duplicated.
4. Duplicate may appear more than twice.

------------------------------------------------------------
Idea

Binary Search is performed on the answer
(value range), NOT on the array indices.

Search Space:

low  = 1
high = n

For every middle value (mid),

Count how many numbers in the array
are less than or equal to mid.

------------------------------------------------------------
Pigeonhole Principle

If there are more than mid numbers
whose value is <= mid,

then the duplicate must lie in
the range [1, mid].

Otherwise,

the duplicate lies in
[mid + 1, n].

------------------------------------------------------------
Binary Search

mid = low + (high - low) / 2

cnt = number of elements <= mid

If cnt > mid
→ Duplicate is in left half.
→ high = mid

Else
→ Duplicate is in right half.
→ low = mid + 1

Answer = low

------------------------------------------------------------
Dry Run

nums = [1,3,4,2,2]

Search Space

low = 1
high = 4

mid = 2

Elements <= 2

1,2,2

Count = 3

3 > 2

Duplicate lies in [1,2]

high = 2

---------------------

low = 1
high = 2

mid = 1

Elements <= 1

1

Count = 1

1 <= 1

Duplicate lies in [2,2]

low = 2

Answer = 2

------------------------------------------------------------
Key Observation

For any value x,

If count(numbers <= x) > x,

then at least one duplicate must exist
within the range [1, x].

This monotonic property allows
Binary Search on the answer.

------------------------------------------------------------
Time Complexity

O(n log n)

where

O(log n)
→ Binary Search

O(n)
→ Count elements for every mid

------------------------------------------------------------
Space Complexity

O(1)

------------------------------------------------------------
Similar Problems

1. First Bad Version
2. Find Peak Element
3. Koko Eating Bananas
4. Split Array Largest Sum
5. Binary Search on Answer
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int low = 1;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            int cnt = 0;

            for (int x : nums) {
                if (x <= mid) {
                    cnt++;
                }
            }

            if (cnt > mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Duplicate Number: "
         << obj.findDuplicate(nums)
         << endl;

    return 0;
}