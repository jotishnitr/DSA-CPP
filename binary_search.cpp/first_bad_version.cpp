/*
------------------------------------------------------------
Problem: First Bad Version
Link: https://leetcode.com/problems/first-bad-version/

Pattern Used:
Binary Search on Answer

Prerequisite:
Versions are ordered such that:

Good Good Good Bad Bad Bad Bad

Once a version becomes bad,
all versions after it are also bad.

This monotonic property allows Binary Search.

------------------------------------------------------------
Brute Force Approach

Idea:
Start from version 1 and check every version
using isBadVersion().

Return the first version which is bad.

Time Complexity:
O(n)

Space Complexity:
O(1)

------------------------------------------------------------
Optimal Approach

Idea:
Binary Search for the first bad version.

Search Space:
low  = 1
high = n

If mid is bad:
→ mid can be the answer.
→ Store it.
→ Search in the left half to find an earlier bad version.

If mid is good:
→ First bad version must lie in the right half.

Binary Search:

if(isBadVersion(mid)){
    ans = mid;
    high = mid - 1;
}
else{
    low = mid + 1;
}

------------------------------------------------------------
Dry Run

n = 10

Versions:

1 2 3 4 5 6 7 8 9 10
G G G B B B B B B B

mid = 5
Bad
ans = 5
Search Left

mid = 2
Good
Search Right

mid = 3
Good
Search Right

mid = 4
Bad
ans = 4
Search Left

Answer = 4

------------------------------------------------------------
Key Observation

Once a version becomes bad,
every version after it is also bad.

So we need to find the first occurrence of
'true' in a monotonic boolean array.

------------------------------------------------------------
Time Complexity

Brute Force:
O(n)

Optimal:
O(log n)

------------------------------------------------------------
Space Complexity

Both Approaches:
O(1)

------------------------------------------------------------
Similar Problems

1. Lower Bound
2. Search Insert Position
3. First and Last Position of Element
4. Find First and Last Occurrence
5. Binary Search on Answer
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Simulated API
int firstBad = 4;

bool isBadVersion(int version) {
    return version >= firstBad;
}

class Solution {
public:

    // Brute Force Approach
    int firstBadVersionBrute(int n) {

        for (int i = 1; i <= n; i++) {
            if (isBadVersion(i)) {
                return i;
            }
        }

        return -1;
    }

    // Optimal Binary Search Approach
    int firstBadVersionOptimal(int n) {

        long long low = 1;
        long long high = n;
        long long ans = n;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (isBadVersion((int)mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};

int main() {

    Solution obj;

    int n = 10;

    cout << "Brute Force Answer  : "
         << obj.firstBadVersionBrute(n)
         << endl;

    cout << "Binary Search Answer: "
         << obj.firstBadVersionOptimal(n)
         << endl;

    return 0;
}